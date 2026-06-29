## Rebase Summary: seen

**From**: [bf5afdecc1](https://github.com/git-for-windows/git/commit/bf5afdecc10478397d7059d07573630902fb2e2f) (Merge 'readme' into HEAD, 2018-06-07) ([07faa066bd..bf5afdecc1](https://github.com/git-for-windows/git/compare/07faa066bdd38fba5893557012c2d9c522a6d386...bf5afdecc10478397d7059d07573630902fb2e2f))

#### Resolved: 1ee8fa8ffc (vcbuild: install ARM64 dependencies when building ARM64 binaries, 2020-01-31)

adapted ARM64 vcpkg_install.bat parameters to use the new lib/compat/vcbuild/ path from upstream

<details>
<summary>Range-diff</summary>

* 1:  1ee8fa8ffc ! 1:  d685f8fcba vcbuild: install ARM64 dependencies when building ARM64 binaries

   ``````diff
   @@ Commit message
        Signed-off-by: Dennis Ameling <dennis@dennisameling.com>
        Signed-off-by: Johannes Schindelin <johannes.schindelin@gmx.de>
    
   - ## compat/vcbuild/README ##
   -@@ compat/vcbuild/README: The Steps to Build Git with VS2015 or VS2017 from the command line.
   + ## lib/compat/vcbuild/README ##
   +@@ lib/compat/vcbuild/README: The Steps to Build Git with VS2015 or VS2017 from the command line.
        Prompt or from an SDK bash window:
     
        $ cd <repo_root>
   --   $ ./compat/vcbuild/vcpkg_install.bat
   -+   $ ./compat/vcbuild/vcpkg_install.bat x64-windows
   +-   $ ./lib/compat/vcbuild/vcpkg_install.bat
   ++   $ ./lib/compat/vcbuild/vcpkg_install.bat x64-windows
    +
    +   or
    +
   -+   $ ./compat/vcbuild/vcpkg_install.bat arm64-windows
   ++   $ ./lib/compat/vcbuild/vcpkg_install.bat arm64-windows
     
        The vcpkg tools and all of the third-party sources will be installed
        in this folder:
    
   - ## compat/vcbuild/vcpkg_copy_dlls.bat ##
   -@@ compat/vcbuild/vcpkg_copy_dlls.bat: REM ================================================================
   + ## lib/compat/vcbuild/vcpkg_copy_dlls.bat ##
   +@@ lib/compat/vcbuild/vcpkg_copy_dlls.bat: REM ================================================================
     	@FOR /F "delims=" %%D IN ("%~dp0") DO @SET cwd=%%~fD
     	cd %cwd%
     
   @@ compat/vcbuild/vcpkg_copy_dlls.bat: REM ========================================
     
     	IF [%1]==[release] (
    
   - ## compat/vcbuild/vcpkg_install.bat ##
   -@@ compat/vcbuild/vcpkg_install.bat: REM ================================================================
   + ## lib/compat/vcbuild/vcpkg_install.bat ##
   +@@ lib/compat/vcbuild/vcpkg_install.bat: REM ================================================================
     
     	SETLOCAL EnableDelayedExpansion
     
   @@ compat/vcbuild/vcpkg_install.bat: REM ==========================================
     	@FOR /F "delims=" %%D IN ("%~dp0") DO @SET cwd=%%~fD
     	cd %cwd%
     
   -@@ compat/vcbuild/vcpkg_install.bat: REM ================================================================
   +@@ lib/compat/vcbuild/vcpkg_install.bat: REM ================================================================
     	echo Successfully installed %cwd%vcpkg\vcpkg.exe
     
     :install_libraries
   ``````

</details>


#### Resolved: 5c06fe1d73 (cmake: allow building for Windows/ARM64, 2020-12-04)

Combined upstream's compat→lib/compat path rename with patch's x64-windows→${VCPKG_ARCH} substitution

<details>
<summary>Range-diff</summary>

* 1:  5c06fe1d73 ! 1:  89244973d2 cmake: allow building for Windows/ARM64

   ``````diff
   @@ Commit message
    
     ## contrib/buildsystems/CMakeLists.txt ##
    @@ contrib/buildsystems/CMakeLists.txt: if(USE_VCPKG)
   - 	set(VCPKG_DIR "${CMAKE_SOURCE_DIR}/compat/vcbuild/vcpkg")
   + 	set(VCPKG_DIR "${CMAKE_SOURCE_DIR}/lib/compat/vcbuild/vcpkg")
     	if(NOT EXISTS ${VCPKG_DIR})
     		message("Initializing vcpkg and building the Git's dependencies (this will take a while...)")
   --		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/compat/vcbuild/vcpkg_install.bat)
   -+		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/compat/vcbuild/vcpkg_install.bat ${VCPKG_ARCH})
   +-		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/lib/compat/vcbuild/vcpkg_install.bat)
   ++		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/lib/compat/vcbuild/vcpkg_install.bat ${VCPKG_ARCH})
     	endif()
    -	list(APPEND CMAKE_PREFIX_PATH "${VCPKG_DIR}/installed/x64-windows")
    +	list(APPEND CMAKE_PREFIX_PATH "${VCPKG_DIR}/installed/${VCPKG_ARCH}")
   @@ contrib/buildsystems/CMakeLists.txt: string(REPLACE "@USE_LIBPCRE2@" "" git_buil
     string(REPLACE "@WITH_BREAKING_CHANGES@" "" git_build_options "${git_build_options}")
     string(REPLACE "@X@" "${EXE_EXTENSION}" git_build_options "${git_build_options}")
     if(USE_VCPKG)
   --	string(APPEND git_build_options "PATH=\"$PATH:$TEST_DIRECTORY/../compat/vcbuild/vcpkg/installed/x64-windows/bin\"\n")
   -+	string(APPEND git_build_options "PATH=\"$PATH:$TEST_DIRECTORY/../compat/vcbuild/vcpkg/installed/${VCPKG_ARCH}/bin\"\n")
   +-	string(APPEND git_build_options "PATH=\"$PATH:$TEST_DIRECTORY/../lib/compat/vcbuild/vcpkg/installed/x64-windows/bin\"\n")
   ++	string(APPEND git_build_options "PATH=\"$PATH:$TEST_DIRECTORY/../lib/compat/vcbuild/vcpkg/installed/${VCPKG_ARCH}/bin\"\n")
     endif()
     file(WRITE ${CMAKE_BINARY_DIR}/GIT-BUILD-OPTIONS ${git_build_options})
     
   ``````

</details>


#### FAILED: c0966a9c29 (ci(vs-build) also build Windows/ARM64 artifacts, 2020-11-29)

Unexpected AI decision: ''. Full output:

```
● Check REBASE_HEAD commit (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && git show --stat REBASE_HEAD && echo "---SUBJECT---" && git log --format=%s -1
  │ REBASE_HEAD
  └ 17 lines…

● Check if upstreamed (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && git range-diff REBASE_HEAD^! REBASE_HEAD..
  └ 11 lines…

The range-diff shows `1: c0966a9c29 < -: ----------` meaning the patch has no upstream equivalent. I need to resolve it surgically. Let me look at the conflict.

● Find conflict markers (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && grep -n "^<<<<<<<\|^=======\|^>>>>>>>" .github/workflows/main.yml
  └ 4 lines…

● See the patch (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && git show REBASE_HEAD -- .github/workflows/main.yml | head -150
  └ 69 lines…

● Read main.yml
  │ ~/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-seen/.github/wo
  │ rkflows/main.yml
  └ L188:218 (31 lines read)

I can see the conflict. Upstream changed `compat\vcbuild\` to `lib\compat\vcbuild\` (a path rename), while the patch adds `${{ matrix.arch }}-windows` parameter and changes paths to use `${{ matrix.arch }}`. I need to combine both: use the upstream's `lib\compat` path AND the patch's `${{ matrix.arch }}` parameterization.

● Edit main.yml +2 -11
  └ ~/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-seen/.github/wo
    rkflows/main.yml

● Verify no remaining conflicts (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && grep -n "^<<<<<<<\|^=======\|^>>>>>>>" .github/workflows/main.yml; echo "exit: $?"
  └ 2 lines…

No conflict markers remain. Let me stage the file.

● Stage resolved file (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/git/rebase-worktree-
  │ seen" && git add .github/workflows/main.yml
  └ 1 line…

Resolved the conflict by combining upstream's `compat` → `lib\compat` path rename with the patch's ARM64 matrix parameterization (`${{ matrix.arch }}-windows`).

continue -- combined upstream's lib/compat path rename with the patch's ARM64 matrix.arch parameterization



Changes    +2 -11
AI Credits 23 (41s)
Tokens     ↑ 182.6k (166.1k cached, 16.5k written) • ↓ 1.8k (16 reasoning)
```

