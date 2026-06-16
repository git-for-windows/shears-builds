## Rebase Summary: main

**From**: [2b58c11d94](https://github.com/git-for-windows/git/commit/2b58c11d94f8ece108ac5493b5a7a9df803e4f24) (Re-enable expensive tests in Windows CI (#6281), 2026-06-16) ([03412da7e1..2b58c11d94](https://github.com/git-for-windows/git/compare/03412da7e196f266307cc28a357b5cca0e5bea28...2b58c11d94f8ece108ac5493b5a7a9df803e4f24))

#### BUILD FAILED: b06b1b85e5 (Merge 'objects-larger-than-4gb-on-windows-pt2', 2026-06-12)

Build failed after conflict resolution. Last 50 lines:

```
    CC upload-pack.o
    CC url.o
    CC urlmatch.o
    CC usage.o
    CC userdiff.o
    CC utf8.o
    GEN version-def.h
    GEN git-difftool--helper
    GEN git-filter-branch
    GEN git-merge-octopus
    GEN git-merge-one-file
    GEN git-merge-resolve
    GEN git-mergetool
    GEN git-quiltimport
    GEN git-request-pull
    GEN git-submodule
    GEN git-web--browse
    GEN GIT-PERL-HEADER
    CC builtin/help.o
    GEN git-archimport
    GEN git-cvsexportcommit
    GEN git-cvsimport
    GEN git-cvsserver
    GEN git-send-email
    GEN git-svn
    CC version.o
    AR libgit.a
    CARGO target/release/libgitcore.a
warning: failed to connect to jobserver from environment variable `MAKEFLAGS=" -j4 --jobserver-auth=3,4"`: cannot open file descriptor 3 from the jobserver environment variable value: Bad file descriptor (os error 9)
    LINK git-daemon
    LINK git-http-backend
    LINK git-imap-send
    LINK git-sh-i18n--envsubst
/usr/bin/ld: /usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-main/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-main/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-main/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-main/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
collect2: error: ld returned 1 exit status
make: *** [Makefile:3011: git-http-backend] Error 1
make: *** Waiting for unfinished jobs....
collect2: error: ld returned 1 exit status
collect2: error: ld returned 1 exit status
make: *** [Makefile:3011: git-daemon] Error 1
make: *** [Makefile:3011: git-sh-i18n--envsubst] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3014: git-imap-send] Error 1
```

