## Rebase Summary: seen

**From**: [2b8a3ab140](https://github.com/git-for-windows/git/commit/2b8a3ab140826ac423c2845ef81d4c6ac4f7bf3c) (Merge 'readme' into HEAD, 2018-06-07) ([81fe37b3dd..2b8a3ab140](https://github.com/git-for-windows/git/compare/81fe37b3dd23c5738a91856fc4aa88c118008218...2b8a3ab140826ac423c2845ef81d4c6ac4f7bf3c))

#### Skipped: 3274ae32fe (sideband: mask control characters, 2024-11-06)

Upstream equivalent: 0494953820 (sideband: mask control characters, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  3274ae32fe ! 1:  0494953820 sideband: mask control characters

   ``````diff
   @@ Commit message
        There is likely a need for more fine-grained controls instead of using a
        "heavy hammer" like this, which will be introduced subsequently.
    
   +    Helped-by: Phillip Wood <phillip.wood@dunelm.org.uk>
        Signed-off-by: Johannes Schindelin <johannes.schindelin@gmx.de>
   +    Signed-off-by: Junio C Hamano <gitster@pobox.com>
    
     ## sideband.c ##
    @@ sideband.c: void list_config_color_sideband_slots(struct string_list *list, const char *pref
   @@ sideband.c: void list_config_color_sideband_slots(struct string_list *list, cons
    +{
    +	strbuf_grow(dest, n);
    +	for (; n && *src; src++, n--) {
   -+		if (!iscntrl(*src) || *src == '\t' || *src == '\n')
   ++		if (!iscntrl(*src) || *src == '\t' || *src == '\n') {
    +			strbuf_addch(dest, *src);
   -+		else {
   ++		} else {
    +			strbuf_addch(dest, '^');
   -+			strbuf_addch(dest, 0x40 + *src);
   ++			strbuf_addch(dest, *src == 0x7f ? '?' : 0x40 + *src);
    +		}
    +	}
    +}
   @@ t/t5409-colorize-remote-messages.sh: test_expect_success 'fallback to color.ui'
    +	printf "error: Have you \\033[31mread\\033[m this?\\n" >&2
    +	exec "$@"
    +	EOF
   -+	test_config_global uploadPack.packObjectshook ./color-me-surprised &&
   ++	test_config_global uploadPack.packObjectsHook ./color-me-surprised &&
    +	test_commit need-at-least-one-commit &&
    +	git clone --no-local . throw-away 2>stderr &&
    +	test_decode_color <stderr >decoded &&
   ``````

</details>


#### Skipped: 0462ca51e3 (sideband: introduce an "escape hatch" to allow control characters, 2024-11-06)

Upstream equivalent: 9ed1625a58 (sideband: introduce an "escape hatch" to allow control characters, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  0462ca51e3 ! 1:  9ed1625a58 sideband: introduce an "escape hatch" to allow control characters

   ``````diff
   @@ Commit message
        To help with those use cases, give users a way to opt-out of the
        protections: `sideband.allowControlCharacters`.
    
   +    Suggested-by: brian m. carlson <sandals@crustytoothpaste.net>
        Signed-off-by: Johannes Schindelin <johannes.schindelin@gmx.de>
   +    Signed-off-by: Junio C Hamano <gitster@pobox.com>
    
     ## Documentation/config.adoc ##
    @@ Documentation/config.adoc: include::config/sequencer.adoc[]
   @@ sideband.c: void list_config_color_sideband_slots(struct string_list *list, cons
    +
     	strbuf_grow(dest, n);
     	for (; n && *src; src++, n--) {
   - 		if (!iscntrl(*src) || *src == '\t' || *src == '\n')
   + 		if (!iscntrl(*src) || *src == '\t' || *src == '\n') {
    
     ## t/t5409-colorize-remote-messages.sh ##
    @@ t/t5409-colorize-remote-messages.sh: test_expect_success 'disallow (color) control sequences in sideband' '
     	EOF
   - 	test_config_global uploadPack.packObjectshook ./color-me-surprised &&
   + 	test_config_global uploadPack.packObjectsHook ./color-me-surprised &&
     	test_commit need-at-least-one-commit &&
    +
     	git clone --no-local . throw-away 2>stderr &&
   ``````

</details>


#### Skipped: 8c8e102ff7 (sideband: do allow ANSI color sequences by default, 2024-11-18)

Upstream equivalent: 12f0fda905 (sideband: do allow ANSI color sequences by default, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  8c8e102ff7 ! 1:  12f0fda905 sideband: do allow ANSI color sequences by default

   ``````diff
   @@ Commit message
        to the terminal, and `sideband.allowControlCharacters` to override that
        behavior.
    
   -    However, some `pre-receive` hooks that are actively used in practice
   -    want to color their messages and therefore rely on the fact that Git
   -    passes them through to the terminal.
   +    However, as reported by brian m. carlson, some `pre-receive` hooks that
   +    are actively used in practice want to color their messages and therefore
   +    rely on the fact that Git passes them through to the terminal, even
   +    though they have no way to determine whether the receiving side can
   +    actually handle Escape sequences (think e.g. about the practice
   +    recommended by Git that third-party applications wishing to use Git
   +    functionality parse the output of Git commands).
    
        In contrast to other ANSI escape sequences, it is highly unlikely that
        coloring sequences can be essential tools in attack vectors that mislead
        Git users e.g. by hiding crucial information.
    
        Therefore we can have both: Continue to allow ANSI coloring sequences to
   -    be passed to the terminal, and neutralize all other ANSI escape
   -    sequences.
   +    be passed to the terminal by default, and neutralize all other ANSI
   +    Escape sequences.
    
        Signed-off-by: Johannes Schindelin <johannes.schindelin@gmx.de>
   +    Signed-off-by: Junio C Hamano <gitster@pobox.com>
    
     ## Documentation/config/sideband.adoc ##
    @@
   @@ Documentation/config/sideband.adoc
    +	this config setting to override this behavior:
    ++
    +--
   -+	color::
   ++	`default`::
   ++	`color`::
    +		Allow ANSI color sequences, line feeds and horizontal tabs,
    +		but mask all other control characters. This is the default.
   -+	false::
   ++	`false`::
    +		Mask all control characters other than line feeds and
    +		horizontal tabs.
   -+	true::
   ++	`true`::
    +		Allow all control characters to be sent to the terminal.
    +--
    
   @@ sideband.c: static struct keyword_entry keywords[] = {
     
    -static int allow_control_characters;
    +static enum {
   -+	ALLOW_NO_CONTROL_CHARACTERS = 0,
   -+	ALLOW_ALL_CONTROL_CHARACTERS = 1,
   -+	ALLOW_ANSI_COLOR_SEQUENCES = 2
   ++	ALLOW_NO_CONTROL_CHARACTERS  = 0,
   ++	ALLOW_ANSI_COLOR_SEQUENCES   = 1<<0,
   ++	ALLOW_DEFAULT_ANSI_SEQUENCES = ALLOW_ANSI_COLOR_SEQUENCES,
   ++	ALLOW_ALL_CONTROL_CHARACTERS = 1<<1,
    +} allow_control_characters = ALLOW_ANSI_COLOR_SEQUENCES;
     
     /* Returns a color setting (GIT_COLOR_NEVER, etc). */
   @@ sideband.c: static enum git_colorbool use_sideband_colors(void)
    +		if (repo_config_get_string_tmp(the_repository, "sideband.allowcontrolcharacters",
    +					      &value))
    +			; /* huh? `get_maybe_bool()` returned -1 */
   ++		else if (!strcmp(value, "default"))
   ++			allow_control_characters = ALLOW_DEFAULT_ANSI_SEQUENCES;
    +		else if (!strcmp(value, "color"))
    +			allow_control_characters = ALLOW_ANSI_COLOR_SEQUENCES;
    +		else
   @@ sideband.c: void list_config_color_sideband_slots(struct string_list *list, cons
    +	 * Valid ANSI color sequences are of the form
    +	 *
    +	 * ESC [ [<n> [; <n>]*] m
   ++	 *
   ++	 * These are part of the Select Graphic Rendition sequences which
   ++	 * contain more than just color sequences, for more details see
   ++	 * https://en.wikipedia.org/wiki/ANSI_escape_code#SGR.
    +	 */
    +
    +	if (allow_control_characters != ALLOW_ANSI_COLOR_SEQUENCES ||
   @@ sideband.c: void list_config_color_sideband_slots(struct string_list *list, cons
     	}
    @@ sideband.c: static void strbuf_add_sanitized(struct strbuf *dest, const char *src, int n)
     	for (; n && *src; src++, n--) {
   - 		if (!iscntrl(*src) || *src == '\t' || *src == '\n')
   + 		if (!iscntrl(*src) || *src == '\t' || *src == '\n') {
     			strbuf_addch(dest, *src);
   --		else {
   -+		else if ((i = handle_ansi_color_sequence(dest, src, n))) {
   ++		} else if ((i = handle_ansi_color_sequence(dest, src, n))) {
    +			src += i;
    +			n -= i;
   -+		} else {
   + 		} else {
     			strbuf_addch(dest, '^');
   - 			strbuf_addch(dest, 0x40 + *src);
   - 		}
   + 			strbuf_addch(dest, *src == 0x7f ? '?' : 0x40 + *src);
    
     ## t/t5409-colorize-remote-messages.sh ##
    @@ t/t5409-colorize-remote-messages.sh: test_expect_success 'fallback to color.ui' '
   @@ t/t5409-colorize-remote-messages.sh: test_expect_success 'fallback to color.ui'
    +	printf "error: Have you \\033[31mread\\033[m this?\\a\\n" >&2
     	exec "$@"
     	EOF
   - 	test_config_global uploadPack.packObjectshook ./color-me-surprised &&
   + 	test_config_global uploadPack.packObjectsHook ./color-me-surprised &&
    @@ t/t5409-colorize-remote-messages.sh: test_expect_success 'disallow (color) control sequences in sideband' '
     
     	git clone --no-local . throw-away 2>stderr &&
   ``````

</details>


#### Resolved: 62db9f4b43 (compat/mingw: handle WSA errors in strerror, 2024-12-22)

kept both u-mingw and u-odb-inmemory entries in alphabetical order in Makefile and t/meson.build

<details>
<summary>Range-diff</summary>

* 1:  62db9f4b43 ! 1:  d78ccacc84 compat/mingw: handle WSA errors in strerror

   ``````diff
   @@ Makefile: CLAR_TEST_SUITES += u-hash
     CLAR_TEST_SUITES += u-list-objects-filter-options
     CLAR_TEST_SUITES += u-mem-pool
    +CLAR_TEST_SUITES += u-mingw
   + CLAR_TEST_SUITES += u-odb-inmemory
     CLAR_TEST_SUITES += u-oid-array
     CLAR_TEST_SUITES += u-oidmap
   - CLAR_TEST_SUITES += u-oidtree
    
     ## compat/mingw-posix.h ##
    @@ compat/mingw-posix.h: int mingw_socket(int domain, int type, int protocol);
   @@ t/meson.build: clar_test_suites = [
       'unit-tests/u-list-objects-filter-options.c',
       'unit-tests/u-mem-pool.c',
    +  'unit-tests/u-mingw.c',
   +   'unit-tests/u-odb-inmemory.c',
       'unit-tests/u-oid-array.c',
       'unit-tests/u-oidmap.c',
   -   'unit-tests/u-oidtree.c',
    
     ## t/unit-tests/u-mingw.c (new) ##
    @@
   ``````

</details>


#### Resolved: 3203a5ceaf (t5563: verify that NTLM authentication works, 2025-11-26)

kept both upstream SPNEGO tests and downstream NTLM test before test_done

<details>
<summary>Range-diff</summary>

* 1:  3203a5ceaf ! 1:  20b09f0679 t5563: verify that NTLM authentication works

   ``````diff
   @@ t/lib-httpd/ntlm-handshake.sh (new)
    +esac
    
     ## t/t5563-simple-http-auth.sh ##
   -@@ t/t5563-simple-http-auth.sh: test_expect_success 'access using three-legged auth' '
   - 	EOF
   +@@ t/t5563-simple-http-auth.sh: test_expect_success SPNEGO 'http.emptyAuth=false skips Negotiate' '
   + 	test_line_count = 1 actual_401s
     '
     
    +test_lazy_prereq NTLM 'curl --version | grep -q NTLM'
   ``````

</details>


#### Dropped (empty after resolution): 7f0f061e18 (http: extract http_reauth_prepare() from retry paths, 2026-04-13)

kept existing empty_auth_try_negotiate early-return in http_reauth_prepare() from prior Git for Windows patch; REBASE_HEAD's new function body is a subset of what HEAD already has


#### Resolved: 8699090aea (tests: use the correct path separator with BusyBox, 2018-11-19)

kept both upstream's errexit block and patch's PATH_SEP detection block, which were independent additions at the same location

<details>
<summary>Range-diff</summary>

* 1:  8699090aea ! 1:  cc362d8c0c tests: use the correct path separator with BusyBox

   ``````diff
   @@ t/t9800-git-p4-basic.sh: test_expect_success 'exit when p4 fails to produce mars
     	) &&
    
     ## t/test-lib.sh ##
   -@@
   - # You should have received a copy of the GNU General Public License
   - # along with this program.  If not, see https://www.gnu.org/licenses/ .
   +@@ t/test-lib.sh: then
   + 	set -e
   + fi
     
    +# On Unix/Linux, the path separator is the colon, on other systems it
    +# may be different, though. On Windows, for example, it is a semicolon.
   ``````

</details>

