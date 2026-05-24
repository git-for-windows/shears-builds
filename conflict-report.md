## Rebase Summary: main

**From**: [a99c60ceeb](https://github.com/git-for-windows/git/commit/a99c60ceeb5a05a8102c0c442203cd9dd92c91e2) (build: tolerate use of _Generic from glibc 2.43 with Clang (#6233), 2026-05-08) ([c2ed2cc6f6..a99c60ceeb](https://github.com/git-for-windows/git/compare/c2ed2cc6f6dd67ef6f0d056cedd566613582a77e...a99c60ceeb5a05a8102c0c442203cd9dd92c91e2))

#### Resolved: 75b3e59c96 (mingw: include the Python parts in the build, 2015-02-16)

added NO_PYTHON= after USE_LIBPCRE line; dropped obsolete USE_NED_ALLOCATOR/CLANGARM64 block that was removed upstream

<details>
<summary>Range-diff</summary>

* 1:  75b3e59c96 ! 1:  a5f690c22c mingw: include the Python parts in the build

   ``````diff
   @@ Commit message
    
     ## config.mak.uname ##
    @@ config.mak.uname: ifeq ($(uname_S),MINGW)
   -         ifneq (CLANGARM64,$(MSYSTEM))
   - 		USE_NED_ALLOCATOR = YesPlease
   -         endif
   + 	HAVE_LIBCHARSET_H = YesPlease
   + 	USE_GETTEXT_SCHEME = fallthrough
   + 	USE_LIBPCRE = YesPlease
    +	NO_PYTHON =
             ifeq (/mingw64,$(subst 32,64,$(subst clangarm,mingw,$(prefix))))
     		# Move system config into top-level /etc/
   ``````

</details>

