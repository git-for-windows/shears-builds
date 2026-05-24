## Rebase Summary: maint

**From**: [126291e800](https://github.com/git-for-windows/git/commit/126291e80013de7291b051cda1daad3ab46a1bc1) (build: tolerate use of _Generic from glibc 2.43 with Clang (#6233), 2026-05-08) ([81fe37b3dd..126291e800](https://github.com/git-for-windows/git/compare/81fe37b3dd23c5738a91856fc4aa88c118008218...126291e80013de7291b051cda1daad3ab46a1bc1))

#### Resolved: eb61d7a11f (mingw: include the Python parts in the build, 2015-02-16)

kept NO_PYTHON= line from patch, dropped removed nedmalloc block that was deleted upstream

<details>
<summary>Range-diff</summary>

* 1:  eb61d7a11f ! 1:  3f0ff12e6a mingw: include the Python parts in the build

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

