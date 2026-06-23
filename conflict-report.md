## Rebase Summary: seen

**From**: [357600da37](https://github.com/git-for-windows/git/commit/357600da376892f8e261063a0bfb1645b26e4aa3) (Merge 'readme' into HEAD, 2018-06-07) ([3a370e9680..357600da37](https://github.com/git-for-windows/git/compare/3a370e9680012f2b6d839efe325a69c4bb7fddf6...357600da376892f8e261063a0bfb1645b26e4aa3))

#### Resolved: af5831d020 (vcbuild: install ARM64 dependencies when building ARM64 binaries, 2020-01-31)

resolved path conflict by combining upstream's lib/ prefix with REBASE_HEAD's ARM64 architecture argument support

<details>
<summary>Range-diff</summary>

* 1:  af5831d020 ! 1:  790932968a vcbuild: install ARM64 dependencies when building ARM64 binaries

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


#### Resolved: 65e6ede9f9 (cmake: allow building for Windows/ARM64, 2020-12-04)

adapted patch to use `lib/compat/vcbuild/` path (upstream rename) while keeping `${VCPKG_ARCH}` substitution from the ARM64 patch

<details>
<summary>Range-diff</summary>

* 1:  65e6ede9f9 ! 1:  f52204c4d1 cmake: allow building for Windows/ARM64

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


#### FAILED: 3fe0907d0f (ci(vs-build) also build Windows/ARM64 artifacts, 2020-11-29)

Unexpected AI decision: ''. Full output:

```
● Check REBASE_HEAD commit (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && git show --stat REBASE_HEAD && echo "---MSG---"
  │ && git log --format=%s -1 REBASE_HEAD
  └ 17 lines...

● Check if patch is upstreamed (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && git range-diff REBASE_HEAD^! REBASE_HEAD.. 2>&1
  │ | head -50
  └ 51 lines...

The range-diff shows `1: 3fe0907d0f < -: ----------` — the patch has no upstream equivalent. I need to resolve it surgically. Let me look at the conflict.

● Find conflict markers (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && grep -n "<<<<<<" .github/workflows/main.yml
  └ 2 lines...

● See the patch diff (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && git show REBASE_HEAD --
  │ .github/workflows/main.yml | head -80
  └ 69 lines...

● Read main.yml
  │ ~/work/git-for-windows-automation/git-for-windows-automation/git/rebase-work
  │ tree-seen/.github/workflows/main.yml
  └ L185:250 (66 lines read)

I can see the conflict. Upstream changed `compat\vcbuild\` to `lib\compat\vcbuild\` (a path restructuring), while the patch adds `${{ matrix.arch }}-windows` parameter and changes the cmake prefix path. I need to combine both: use the `lib\compat\vcbuild\` path AND apply the matrix.arch changes.

● Edit main.yml +2 -11
  └ ~/work/git-for-windows-automation/git-for-windows-automation/git/rebase-work
    tree-seen/.github/workflows/main.yml

● Verify no remaining markers (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && grep -n "<<<<<<\|======\|>>>>>>"
  │ .github/workflows/main.yml | head -5
  └ 1 line...

No remaining conflict markers. Let me stage the file.

● Stage resolved file (shell)
  │ cd "/home/runner/work/git-for-windows-automation/git-for-windows-automation/
  │ git/rebase-worktree-seen" && git add .github/workflows/main.yml
  └ 1 line...

The conflict was between upstream's path restructuring (`compat/vcbuild/` → `lib/compat/vcbuild/`) and the patch's ARM64 matrix additions. I applied the matrix.arch parameterization on top of the new `lib/compat/vcbuild/` paths.

continue -- combined upstream's lib/compat/vcbuild path restructuring with the patch's matrix.arch parameterization for ARM64 build support



Changes    +2 -11
AI Credits 25.7 (40s)
Tokens     ↑ 195.9k (176.1k cached, 19.8k written) • ↓ 1.8k (18 reasoning)
```

