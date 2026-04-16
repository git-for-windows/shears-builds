## Rebase Summary: seen

**From**: [7d8b4efad6](https://github.com/git-for-windows/git/commit/7d8b4efad656bf8b67e38aab8cc01864943dcacf) (Merge 'readme' into HEAD, 2018-06-07) ([9a274180f1..7d8b4efad6](https://github.com/git-for-windows/git/compare/9a274180f1d4554be73ac6a1a41d07c8e1fde4b6...7d8b4efad656bf8b67e38aab8cc01864943dcacf))

#### Skipped: 679b1fcf5b (sideband: mask control characters, 2024-11-06)

Upstream equivalent: 0494953820 (sideband: mask control characters, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  679b1fcf5b ! 1:  0494953820 sideband: mask control characters

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


#### Skipped: 7227785b34 (sideband: introduce an "escape hatch" to allow control characters, 2024-11-06)

Upstream equivalent: 9ed1625a58 (sideband: introduce an "escape hatch" to allow control characters, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  7227785b34 ! 1:  9ed1625a58 sideband: introduce an "escape hatch" to allow control characters

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


#### Skipped: eb92506c18 (sideband: do allow ANSI color sequences by default, 2024-11-18)

Upstream equivalent: 12f0fda905 (sideband: do allow ANSI color sequences by default, 2026-03-05)

<details>
<summary>Range-diff</summary>

* 1:  eb92506c18 ! 1:  12f0fda905 sideband: do allow ANSI color sequences by default

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


#### BUILD FAILED: c5281e48d2 (Merge branch 'v2.53.0.windows.3', 2026-04-14)

Build failed after conflict resolution. Last 50 lines:

```
    CC t/helper/test-read-graph.o
    CC t/helper/test-read-midx.o
    CC t/helper/test-ref-store.o
    CC t/helper/test-reftable.o
    CC t/helper/test-regex.o
    CC t/helper/test-rot13-filter.o
    CC t/helper/test-repository.o
    CC t/helper/test-revision-walking.o
    CC t/helper/test-run-command.o
    CC t/helper/test-scrap-cache-tree.o
    CC t/helper/test-serve-v2.o
    CC t/helper/test-sha1.o
    CC t/helper/test-sha256.o
    CC t/helper/test-sigchain.o
    CC t/helper/test-simple-ipc.o
    CC t/helper/test-string-list.o
    CC t/helper/test-submodule-config.o
    CC t/helper/test-submodule-nested-repo-config.o
    CC t/helper/test-submodule.o
    CC t/helper/test-subprocess.o
    CC t/helper/test-trace2.o
    CC t/helper/test-truncate.o
    CC t/helper/test-userdiff.o
    CC t/helper/test-wildmatch.o
    CC t/helper/test-windows-named-pipe.o
    CC t/helper/test-write-cache.o
    CC t/helper/test-xml-encode.o
    CC t/helper/test-zlib.o
    CC t/unit-tests/test-lib.o
    GEN bin-wrappers/git
    GEN bin-wrappers/scalar
    GEN bin-wrappers/git-receive-pack
    GEN bin-wrappers/git-shell
    GEN bin-wrappers/git-upload-archive
    GEN bin-wrappers/git-upload-pack
    GEN bin-wrappers/git-cvsserver
    GEN bin-wrappers/test-fake-ssh
    GEN bin-wrappers/test-tool
    * new test suites
    LINK t/helper/test-fake-ssh
    GEN t/unit-tests/clar-decls.h
    LINK t/helper/test-tool
    GEN t/unit-tests/clar.suite
    CC t/unit-tests/u-ctype.o
    CC t/unit-tests/u-dir.o
    CC t/unit-tests/u-example-decorate.o
/usr/bin/ld: t/helper/test-tool.o:(.data.rel.ro+0x1d8): undefined reference to `cmd__iconv'
collect2: error: ld returned 1 exit status
make: *** [Makefile:3411: t/helper/test-tool] Error 1
make: *** Waiting for unfinished jobs....
```

