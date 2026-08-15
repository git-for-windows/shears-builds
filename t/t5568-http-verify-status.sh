#!/bin/sh

test_description='http.sslVerifyStatus'

GIT_TEST_DEFAULT_INITIAL_BRANCH_NAME=main
export GIT_TEST_DEFAULT_INITIAL_BRANCH_NAME

. ./test-lib.sh

LIB_HTTPD_SSL=t
. "$TEST_DIRECTORY"/lib-httpd.sh
start_httpd

# The test server staples no OCSP response, and that is what makes this
# testable without standing up a CA and a responder: http.sslVerifyStatus is
# fail-closed, so turning it on has to turn a working fetch into a failing one.
#
# lib-httpd.sh exports GIT_SSL_NO_VERIFY for its self-signed certificate. In
# libcurl the status check is independent of peer verification, so it still
# applies here.

test_expect_success 'setup repository' '
	echo content >file &&
	git add file &&
	git commit -m one
'

test_expect_success 'create http-accessible bare repository' '
	git init --bare "$HTTPD_DOCUMENT_ROOT_PATH/repo.git" &&
	git remote add public "$HTTPD_DOCUMENT_ROOT_PATH/repo.git" &&
	git push public main:main
'

# A TLS backend that cannot check the staple makes curl_easy_setopt() fail,
# which http.c reports with a distinct message. Skip in that case rather than
# reporting a failure that really means "this libcurl was built differently".
# Any other failure leaves the prerequisite satisfied on purpose, so a broken
# server makes the tests below fail loudly instead of silently vanishing.
test_lazy_prereq SSL_VERIFYSTATUS '
	git -c http.sslVerifyStatus=true \
		ls-remote "$HTTPD_URL/smart/repo.git" 2>err &&
	! grep "cannot verify certificate status" err
'

test_expect_success 'ls-remote succeeds with http.sslVerifyStatus unset' '
	git ls-remote "$HTTPD_URL/smart/repo.git" >actual &&
	test_line_count -gt 0 actual
'

test_expect_success SSL_VERIFYSTATUS 'http.sslVerifyStatus=true fails without a staple' '
	test_must_fail git -c http.sslVerifyStatus=true \
		ls-remote "$HTTPD_URL/smart/repo.git"
'

test_expect_success SSL_VERIFYSTATUS 'http.sslVerifyStatus=false is a no-op' '
	git -c http.sslVerifyStatus=false \
		ls-remote "$HTTPD_URL/smart/repo.git" >actual &&
	test_line_count -gt 0 actual
'

test_expect_success SSL_VERIFYSTATUS 'per-URL configuration applies to a matching URL' '
	test_must_fail git -c "http.$HTTPD_URL/.sslVerifyStatus=true" \
		ls-remote "$HTTPD_URL/smart/repo.git"
'

test_expect_success SSL_VERIFYSTATUS 'per-URL configuration is not applied to other URLs' '
	git -c "http.https://example.com/.sslVerifyStatus=true" \
		ls-remote "$HTTPD_URL/smart/repo.git" >actual &&
	test_line_count -gt 0 actual
'

test_done
