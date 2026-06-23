## Rebase Summary: main

**From**: [39fbdf4766](https://github.com/git-for-windows/git/commit/39fbdf47660ae2e360118b8ce3e0e2a2448f5b0a) (Continue improving support for 4GB+ packs/clones/objects (#6289), 2026-06-23) ([bd4d1720b1..39fbdf4766](https://github.com/git-for-windows/git/compare/bd4d1720b1871322e49b9d06135bcf717d5b1775...39fbdf47660ae2e360118b8ce3e0e2a2448f5b0a))

#### BUILD FAILED: 8d64f66f17 (Merge branch 'size-t/pack-objects-delta', 2026-06-07)

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
collect2: error: ld returned 1 exit status
make: *** [Makefile:3011: git-sh-i18n--envsubst] Error 1
make: *** Waiting for unfinished jobs....
make: *** [Makefile:3011: git-daemon] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3011: git-http-backend] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3014: git-imap-send] Error 1
```

