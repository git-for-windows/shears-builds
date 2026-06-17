## Rebase Summary: next

**From**: [eae40bb83e](https://github.com/git-for-windows/git/commit/eae40bb83eaab2220d9ab18330b0f12cbb16797d) (Re-enable expensive tests in Windows CI (#6281), 2026-06-16) ([7ecd379e06..eae40bb83e](https://github.com/git-for-windows/git/compare/7ecd379e063a5ea8530a9a8de4c77bd1c3acd0ff...eae40bb83eaab2220d9ab18330b0f12cbb16797d))

#### BUILD FAILED: 24459c91c5 (Merge 'objects-larger-than-4gb-on-windows-pt2', 2026-06-12)

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
/usr/bin/ld/usr/bin/ld: : libgit.a(object-file.o)libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:348:(.text+0x1f80): undefined reference to `quick_has_loose'
: in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:348:(.text+0x1f80): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:348:(.text+0x1f80): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:348:(.text+0x1f80): undefined reference to `quick_has_loose'
collect2: error: ld returned 1 exit status
collect2: error: ld returned 1 exit status
collect2: error: ld returned 1 exit status
make: *** [Makefile:3011: git-daemon] Error 1
make: *** Waiting for unfinished jobs....
make: *** [Makefile:3011: git-http-backend] Error 1
make: *** [Makefile:3011: git-sh-i18n--envsubst] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3014: git-imap-send] Error 1
```

