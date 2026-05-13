## Rebase Summary: next

**From**: [45ef3336e3](https://github.com/git-for-windows/git/commit/45ef3336e322603e5be6a412ff2e9458f4841c43) (build: tolerate use of _Generic from glibc 2.43 with Clang (#6233), 2026-05-08) ([6d8316c4e0..45ef3336e3](https://github.com/git-for-windows/git/compare/6d8316c4e0f09d5050eb8ae2fa0bec872bba80d2...45ef3336e322603e5be6a412ff2e9458f4841c43))

#### Resolved: 4b0ff0a525 (mingw: include the Python parts in the build, 2015-02-16)

kept NO_PYTHON= line, dropped nedmalloc block removed upstream

<details>
<summary>Range-diff</summary>

* 1:  4b0ff0a525 ! 1:  19e8ff1dd1 mingw: include the Python parts in the build

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

