## Rebase Summary: next

**From**: [32f31d4f48](https://github.com/git-for-windows/git/commit/32f31d4f48b3ebdb70a73a5f1f6bffe69c844dd7) (Continue improving support for 4GB+ packs/clones/objects (#6289), 2026-06-23) ([457ab90ae5..32f31d4f48](https://github.com/git-for-windows/git/compare/457ab90ae5cec4614fd5ce164d545e62726f4fdc...32f31d4f48b3ebdb70a73a5f1f6bffe69c844dd7))

#### BUILD FAILED: 674a64541a (Merge branch 'size-t/pack-objects-delta', 2026-06-07)

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
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:347:(.text+0x1f80libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
/usr/bin/ld: libgit.a(object-file.o): in function `read_object_info_from_path':
/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-next/object-file.c:347:(.text+0x1f80): undefined reference to `quick_has_loose'
collect2: error: ld returned 1 exit status
make: *** [Makefile:3013: git-daemon] Error 1
collect2: error: ld returned 1 exit status
make: *** Waiting for unfinished jobs....
make: *** [Makefile:3013: git-http-backend] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3013: git-sh-i18n--envsubst] Error 1
collect2: error: ld returned 1 exit status
make: *** [Makefile:3016: git-imap-send] Error 1
```

