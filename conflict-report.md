## Rebase Summary: next

**From**: [5b35fd9710](https://github.com/git-for-windows/git/commit/5b35fd9710be837db2e8311f88d7aefb330c7e52) (ci: bump debian-11 job to debian-12 (#6401), 2026-09-08) ([9719ed0ced..5b35fd9710](https://github.com/git-for-windows/git/compare/9719ed0ced060f852c9719fdfd6cd1a31b5ebb68...5b35fd9710be837db2e8311f88d7aefb330c7e52))

#### Resolved: 4b188a3509 (Merge tag 'v2.55.0.windows.5', 2026-08-21)

resolved merge of v2.55.0.windows.5 tag: kept upstream's survey deprecation, size_t unifications, CI_EVENT rename, test_grep usage, and strbuf_add in setup.c; preserved Windows-specific mimalloc monitor entry, mingw_platform_has_symlinks(), and path-utils includes

<details>
<summary>Range-diff</summary>

* 1:  4b188a3509 ! 1:  dda1b2aa12 Merge tag 'v2.55.0.windows.5'

   ``````diff
   @@ Commit message
        Signed-off-by: Matthew John Cheetham <mjcheetham@outlook.com>
    
     ## .github/workflows/monitor-components.yml ##
   + remerge CONFLICT (add/add): Merge conflict in .github/workflows/monitor-components.yml
   + index 5597f7bb0f..f15ff218d2 100644
   + --- .github/workflows/monitor-components.yml
   + +++ .github/workflows/monitor-components.yml
    @@ .github/workflows/monitor-components.yml: jobs:
                 feed: https://github.com/msys2/MINGW-packages/commits/master/mingw-w64-llvm.atom
               - label: innosetup
                 feed: https://github.com/jrsoftware/issrc/tags.atom
   -+          - label: mimalloc
   -+            feed: https://github.com/microsoft/mimalloc/tags.atom
   -+            title-pattern: ^(?!v1\.|v3\.[01]\.)
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   +-=======
   +           - label: mimalloc
   +             feed: https://github.com/microsoft/mimalloc/tags.atom
   +             title-pattern: ^(?!v1\.|v3\.[01]\.)
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
           fail-fast: false
         steps:
           - uses: git-for-windows/rss-to-issues@v0
    
   + ## Documentation/git-survey.adoc ##
   + remerge CONFLICT (add/add): Merge conflict in Documentation/git-survey.adoc
   + index 0fad9621a9..e97656b49d 100644
   + --- Documentation/git-survey.adoc
   + +++ Documentation/git-survey.adoc
   +@@ Documentation/git-survey.adoc: git-survey(1)
   + 
   + NAME
   + ----
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + git-survey - DEPRECATED: Measure various repository dimensions of scale
   +-=======
   +-git-survey - EXPERIMENTAL: Measure various repository dimensions of scale
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + SYNOPSIS
   + --------
   + [verse]
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + (DEPRECATED!) 'git survey' <options>
   +-=======
   +-(EXPERIMENTAL!) 'git survey' <options>
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + DESCRIPTION
   + -----------
   + 
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + NOTE: `git survey` is being superseded by `git repo structure`. New
   + deployments and new features should use `git repo structure`; its
   + `--ref-filter=<pattern>` option subsumes the various `--branches`,
   +@@ Documentation/git-survey.adoc: deployments and new features should use `git repo structure`; its
   + same detail tables. During the deprecation phase, `git survey` is
   + a thin shim over `git repo structure`. See linkgit:git-repo[1].
   + 
   +-=======
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + Survey the repository and measure various dimensions of scale.
   + 
   + As repositories grow to "monorepo" size, certain data shapes can cause
   +
   + ## builtin/fast-import.c ##
   + remerge CONFLICT (content): Merge conflict in builtin/fast-import.c
   + index 548650968a..c28df068fd 100644
   + --- builtin/fast-import.c
   + +++ builtin/fast-import.c
   +@@ builtin/fast-import.c: static void cat_blob_write(const char *buf, unsigned long size)
   + static void cat_blob(struct object_entry *oe, struct object_id *oid)
   + {
   + 	struct strbuf line = STRBUF_INIT;
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	struct iovec iov[3];
   +-=======
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 	size_t size;
   + 	enum object_type type = 0;
   + 	char *buf;
   +
   + ## builtin/pack-objects.c ##
   + remerge CONFLICT (content): Merge conflict in builtin/pack-objects.c
   + index 38bb1e53e5..438bdb359b 100644
   + --- builtin/pack-objects.c
   + +++ builtin/pack-objects.c
   +@@ builtin/pack-objects.c: static void check_object(struct object_entry *entry, uint32_t object_index)
   + 		int have_base = 0;
   + 		struct object_id base_ref;
   + 		struct object_entry *base_entry;
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 		size_t used, used_0, avail;
   +-=======
   +-		unsigned long used, used_0;
   +-		size_t avail;
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 		off_t ofs;
   + 		unsigned char *buf, c;
   + 		enum object_type type;
   +@@ builtin/pack-objects.c: size_t oe_get_size_slow(struct packing_data *pack,
   + 	struct pack_window *w_curs;
   + 	unsigned char *buf;
   + 	enum object_type type;
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	size_t used, avail, size;
   +-=======
   +-	unsigned long used;
   +-	size_t avail, size;
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + 	if (e->type_ != OBJ_OFS_DELTA && e->type_ != OBJ_REF_DELTA) {
   + 		size_t sz;
   +
   + ## builtin/survey.c ##
   + remerge CONFLICT (add/add): Merge conflict in builtin/survey.c
   + index 6f7f887d1b..d3b36b8914 100644
   + --- builtin/survey.c
   + +++ builtin/survey.c
   +@@
   + #define USE_THE_REPOSITORY_VARIABLE
   + 
   + #include "builtin.h"
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + #include "color.h"
   + #include "exec-cmd.h"
   + #include "gettext.h"
   +@@ builtin/survey.c: int cmd_survey(int argc, const char **argv, const char *prefix,
   + 	/* unreachable: execv_git_cmd dies on failure */
   + 	strvec_clear(&child_argv);
   + 	return 1;
   +-=======
   +-#include "config.h"
   +-#include "environment.h"
   +-#include "hex.h"
   +-#include "object.h"
   +-#include "odb.h"
   +-#include "object-name.h"
   +-#include "parse-options.h"
   +-#include "path-walk.h"
   +-#include "progress.h"
   +-#include "ref-filter.h"
   +-#include "refs.h"
   +-#include "revision.h"
   +-#include "strbuf.h"
   +-#include "strvec.h"
   +-#include "tag.h"
   +-#include "trace2.h"
   +-#include "color.h"
   +-
   +-static const char * const survey_usage[] = {
   +-	N_("(EXPERIMENTAL!) git survey <options>"),
   +-	NULL,
   +-};
   +-
   +-struct survey_refs_wanted {
   +-	int want_all_refs; /* special override */
   +-
   +-	int want_branches;
   +-	int want_tags;
   +-	int want_remotes;
   +-	int want_detached;
   +-	int want_other; /* see FILTER_REFS_OTHERS -- refs/notes/, refs/stash/ */
   +-};
   +-
   +-static struct survey_refs_wanted default_ref_options = {
   +-	.want_all_refs = 1,
   +-};
   +-
   +-struct survey_opts {
   +-	int verbose;
   +-	int show_progress;
   +-	int top_nr;
   +-	struct survey_refs_wanted refs;
   +-};
   +-
   +-struct survey_report_ref_summary {
   +-	size_t refs_nr;
   +-	size_t branches_nr;
   +-	size_t remote_refs_nr;
   +-	size_t tags_nr;
   +-	size_t tags_annotated_nr;
   +-	size_t others_nr;
   +-	size_t unknown_nr;
   +-};
   +-
   +-struct survey_report_object_summary {
   +-	size_t commits_nr;
   +-	size_t tags_nr;
   +-	size_t trees_nr;
   +-	size_t blobs_nr;
   +-};
   +-
   +-/**
   +- * For some category given by 'label', count the number of objects
   +- * that match that label along with the on-disk size and the size
   +- * after decompressing (both with delta bases and zlib).
   +- */
   +-struct survey_report_object_size_summary {
   +-	char *label;
   +-	size_t nr;
   +-	size_t disk_size;
   +-	size_t inflated_size;
   +-	size_t num_missing;
   +-};
   +-
   +-typedef int (*survey_top_cmp)(void *v1, void *v2);
   +-
   +-static int cmp_by_nr(void *v1, void *v2)
   +-{
   +-	struct survey_report_object_size_summary *s1 = v1;
   +-	struct survey_report_object_size_summary *s2 = v2;
   +-
   +-	if (s1->nr < s2->nr)
   +-		return -1;
   +-	if (s1->nr > s2->nr)
   +-		return 1;
   +-	return 0;
   +-}
   +-
   +-static int cmp_by_disk_size(void *v1, void *v2)
   +-{
   +-	struct survey_report_object_size_summary *s1 = v1;
   +-	struct survey_report_object_size_summary *s2 = v2;
   +-
   +-	if (s1->disk_size < s2->disk_size)
   +-		return -1;
   +-	if (s1->disk_size > s2->disk_size)
   +-		return 1;
   +-	return 0;
   +-}
   +-
   +-static int cmp_by_inflated_size(void *v1, void *v2)
   +-{
   +-	struct survey_report_object_size_summary *s1 = v1;
   +-	struct survey_report_object_size_summary *s2 = v2;
   +-
   +-	if (s1->inflated_size < s2->inflated_size)
   +-		return -1;
   +-	if (s1->inflated_size > s2->inflated_size)
   +-		return 1;
   +-	return 0;
   +-}
   +-
   +-/**
   +- * Store a list of "top" categories by some sorting function. When
   +- * inserting a new category, reorder the list and free the one that
   +- * got ejected (if any).
   +- */
   +-struct survey_report_top_table {
   +-	const char *name;
   +-	survey_top_cmp cmp_fn;
   +-	size_t nr;
   +-	size_t alloc;
   +-
   +-	/**
   +-	 * 'data' stores an array of structs and must be cast into
   +-	 * the proper array type before evaluating an index.
   +-	 */
   +-	void *data;
   +-};
   +-
   +-static void init_top_sizes(struct survey_report_top_table *top,
   +-			   size_t limit, const char *name,
   +-			   survey_top_cmp cmp)
   +-{
   +-	struct survey_report_object_size_summary *sz_array;
   +-
   +-	top->name = name;
   +-	top->cmp_fn = cmp;
   +-	top->alloc = limit;
   +-	top->nr = 0;
   +-
   +-	CALLOC_ARRAY(sz_array, limit);
   +-	top->data = sz_array;
   +-}
   +-
   +-MAYBE_UNUSED
   +-static void clear_top_sizes(struct survey_report_top_table *top)
   +-{
   +-	struct survey_report_object_size_summary *sz_array = top->data;
   +-
   +-	for (size_t i = 0; i < top->nr; i++)
   +-		free(sz_array[i].label);
   +-	free(sz_array);
   +-}
   +-
   +-static void maybe_insert_into_top_size(struct survey_report_top_table *top,
   +-				       struct survey_report_object_size_summary *summary)
   +-{
   +-	struct survey_report_object_size_summary *sz_array = top->data;
   +-	size_t pos = top->nr;
   +-
   +-	/* Compare against list from the bottom. */
   +-	while (pos > 0 && top->cmp_fn(&sz_array[pos - 1], summary) < 0)
   +-		pos--;
   +-
   +-	/* Not big enough! */
   +-	if (pos >= top->alloc)
   +-		return;
   +-
   +-	/* We need to shift the data. */
   +-	if (top->nr == top->alloc)
   +-		free(sz_array[top->nr - 1].label);
   +-	else
   +-		top->nr++;
   +-
   +-	for (size_t i = top->nr - 1; i > pos; i--)
   +-		memcpy(&sz_array[i], &sz_array[i - 1], sizeof(*sz_array));
   +-
   +-	memcpy(&sz_array[pos], summary, sizeof(*summary));
   +-	sz_array[pos].label = xstrdup(summary->label);
   +-}
   +-
   +-/**
   +- * This struct contains all of the information that needs to be printed
   +- * at the end of the exploration of the repository and its references.
   +- */
   +-struct survey_report {
   +-	struct survey_report_ref_summary refs;
   +-	struct survey_report_object_summary reachable_objects;
   +-
   +-	struct survey_report_object_size_summary *by_type;
   +-
   +-	struct survey_report_top_table *top_paths_by_count;
   +-	struct survey_report_top_table *top_paths_by_disk;
   +-	struct survey_report_top_table *top_paths_by_inflate;
   +-};
   +-
   +-#define REPORT_TYPE_COMMIT 0
   +-#define REPORT_TYPE_TREE 1
   +-#define REPORT_TYPE_BLOB 2
   +-#define REPORT_TYPE_TAG 3
   +-#define REPORT_TYPE_COUNT 4
   +-
   +-struct survey_context {
   +-	struct repository *repo;
   +-
   +-	/* Options that control what is done. */
   +-	struct survey_opts opts;
   +-
   +-	/* Info for output only. */
   +-	struct survey_report report;
   +-
   +-	/*
   +-	 * The rest of the members are about enabling the activity
   +-	 * of the 'git survey' command, including ref listings, object
   +-	 * pointers, and progress.
   +-	 */
   +-
   +-	struct progress *progress;
   +-	size_t progress_nr;
   +-	size_t progress_total;
   +-
   +-	struct strvec refs;
   +-	struct ref_array ref_array;
   +-};
   +-
   +-static void clear_survey_context(struct survey_context *ctx)
   +-{
   +-	ref_array_clear(&ctx->ref_array);
   +-	strvec_clear(&ctx->refs);
   +-}
   +-
   +-struct survey_table {
   +-	const char *table_name;
   +-	struct strvec header;
   +-	struct strvec *rows;
   +-	size_t rows_nr;
   +-	size_t rows_alloc;
   +-};
   +-
   +-#define SURVEY_TABLE_INIT {	\
   +-	.header = STRVEC_INIT,	\
   +-}
   +-
   +-static void clear_table(struct survey_table *table)
   +-{
   +-	strvec_clear(&table->header);
   +-	for (size_t i = 0; i < table->rows_nr; i++)
   +-		strvec_clear(&table->rows[i]);
   +-	free(table->rows);
   +-}
   +-
   +-static void insert_table_rowv(struct survey_table *table, ...)
   +-{
   +-	va_list ap;
   +-	char *arg;
   +-	ALLOC_GROW(table->rows, table->rows_nr + 1, table->rows_alloc);
   +-
   +-	memset(&table->rows[table->rows_nr], 0, sizeof(struct strvec));
   +-
   +-	va_start(ap, table);
   +-	while ((arg = va_arg(ap, char *)))
   +-		strvec_push(&table->rows[table->rows_nr], arg);
   +-	va_end(ap);
   +-
   +-	table->rows_nr++;
   +-}
   +-
   +-#define SECTION_SEGMENT "========================================"
   +-#define SECTION_SEGMENT_LEN 40
   +-static const char *section_line = SECTION_SEGMENT
   +-				  SECTION_SEGMENT
   +-				  SECTION_SEGMENT
   +-				  SECTION_SEGMENT;
   +-static const size_t section_len = 4 * SECTION_SEGMENT_LEN;
   +-
   +-static void print_table_title(const char *name, size_t *widths, size_t nr)
   +-{
   +-	size_t width = 3 * (nr - 1);
   +-	size_t min_width = strlen(name);
   +-
   +-	for (size_t i = 0; i < nr; i++)
   +-		width += widths[i];
   +-
   +-	if (width < min_width)
   +-		width = min_width;
   +-
   +-	if (width > section_len)
   +-		width = section_len;
   +-
   +-	printf("\n%s\n%.*s\n", name, (int)width, section_line);
   +-}
   +-
   +-static void print_row_plaintext(struct strvec *row, size_t *widths)
   +-{
   +-	static struct strbuf line = STRBUF_INIT;
   +-	strbuf_setlen(&line, 0);
   +-
   +-	for (size_t i = 0; i < row->nr; i++) {
   +-		const char *str = row->v[i];
   +-		size_t len = strlen(str);
   +-		if (i)
   +-			strbuf_add(&line, " | ", 3);
   +-		strbuf_addchars(&line, ' ', widths[i] - len);
   +-		strbuf_add(&line, str, len);
   +-	}
   +-	printf("%s\n", line.buf);
   +-}
   +-
   +-static void print_divider_plaintext(size_t *widths, size_t nr)
   +-{
   +-	static struct strbuf line = STRBUF_INIT;
   +-	strbuf_setlen(&line, 0);
   +-
   +-	for (size_t i = 0; i < nr; i++) {
   +-		if (i)
   +-			strbuf_add(&line, "-+-", 3);
   +-		strbuf_addchars(&line, '-', widths[i]);
   +-	}
   +-	printf("%s\n", line.buf);
   +-}
   +-
   +-static void print_table_plaintext(struct survey_table *table)
   +-{
   +-	size_t *column_widths;
   +-	size_t columns_nr = table->header.nr;
   +-	CALLOC_ARRAY(column_widths, columns_nr);
   +-
   +-	for (size_t i = 0; i < columns_nr; i++) {
   +-		column_widths[i] = strlen(table->header.v[i]);
   +-
   +-		for (size_t j = 0; j < table->rows_nr; j++) {
   +-			size_t rowlen = strlen(table->rows[j].v[i]);
   +-			if (column_widths[i] < rowlen)
   +-				column_widths[i] = rowlen;
   +-		}
   +-	}
   +-
   +-	print_table_title(table->table_name, column_widths, columns_nr);
   +-	print_row_plaintext(&table->header, column_widths);
   +-	print_divider_plaintext(column_widths, columns_nr);
   +-
   +-	for (size_t j = 0; j < table->rows_nr; j++)
   +-		print_row_plaintext(&table->rows[j], column_widths);
   +-
   +-	free(column_widths);
   +-}
   +-
   +-static void survey_report_plaintext_refs(struct survey_context *ctx)
   +-{
   +-	struct survey_report_ref_summary *refs = &ctx->report.refs;
   +-	struct survey_table table = SURVEY_TABLE_INIT;
   +-
   +-	table.table_name = _("REFERENCES SUMMARY");
   +-
   +-	strvec_push(&table.header, _("Ref Type"));
   +-	strvec_push(&table.header, _("Count"));
   +-
   +-	if (ctx->opts.refs.want_all_refs || ctx->opts.refs.want_branches) {
   +-		char *fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)refs->branches_nr);
   +-		insert_table_rowv(&table, _("Branches"), fmt, NULL);
   +-		free(fmt);
   +-	}
   +-
   +-	if (ctx->opts.refs.want_all_refs || ctx->opts.refs.want_remotes) {
   +-		char *fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)refs->remote_refs_nr);
   +-		insert_table_rowv(&table, _("Remote refs"), fmt, NULL);
   +-		free(fmt);
   +-	}
   +-
   +-	if (ctx->opts.refs.want_all_refs || ctx->opts.refs.want_tags) {
   +-		char *fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)refs->tags_nr);
   +-		insert_table_rowv(&table, _("Tags (all)"), fmt, NULL);
   +-		free(fmt);
   +-		fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)refs->tags_annotated_nr);
   +-		insert_table_rowv(&table, _("Tags (annotated)"), fmt, NULL);
   +-		free(fmt);
   +-	}
   +-
   +-	print_table_plaintext(&table);
   +-	clear_table(&table);
   +-}
   +-
   +-static void survey_report_plaintext_reachable_object_summary(struct survey_context *ctx)
   +-{
   +-	struct survey_report_object_summary *objs = &ctx->report.reachable_objects;
   +-	struct survey_table table = SURVEY_TABLE_INIT;
   +-	char *fmt;
   +-
   +-	table.table_name = _("REACHABLE OBJECT SUMMARY");
   +-
   +-	strvec_push(&table.header, _("Object Type"));
   +-	strvec_push(&table.header, _("Count"));
   +-
   +-	fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)objs->tags_nr);
   +-	insert_table_rowv(&table, _("Tags"), fmt, NULL);
   +-	free(fmt);
   +-
   +-	fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)objs->commits_nr);
   +-	insert_table_rowv(&table, _("Commits"), fmt, NULL);
   +-	free(fmt);
   +-
   +-	fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)objs->trees_nr);
   +-	insert_table_rowv(&table, _("Trees"), fmt, NULL);
   +-	free(fmt);
   +-
   +-	fmt = xstrfmt("%"PRIuMAX"", (uintmax_t)objs->blobs_nr);
   +-	insert_table_rowv(&table, _("Blobs"), fmt, NULL);
   +-	free(fmt);
   +-
   +-	print_table_plaintext(&table);
   +-	clear_table(&table);
   +-}
   +-
   +-static void survey_report_object_sizes(const char *title,
   +-				       const char *categories,
   +-				       struct survey_report_object_size_summary *summary,
   +-				       size_t summary_nr)
   +-{
   +-	struct survey_table table = SURVEY_TABLE_INIT;
   +-	table.table_name = title;
   +-
   +-	strvec_push(&table.header, categories);
   +-	strvec_push(&table.header, _("Count"));
   +-	strvec_push(&table.header, _("Disk Size"));
   +-	strvec_push(&table.header, _("Inflated Size"));
   +-
   +-	for (size_t i = 0; i < summary_nr; i++) {
   +-		char *label_str =  xstrdup(summary[i].label);
   +-		char *nr_str = xstrfmt("%"PRIuMAX, (uintmax_t)summary[i].nr);
   +-		char *disk_str = xstrfmt("%"PRIuMAX, (uintmax_t)summary[i].disk_size);
   +-		char *inflate_str = xstrfmt("%"PRIuMAX, (uintmax_t)summary[i].inflated_size);
   +-
   +-		insert_table_rowv(&table, label_str, nr_str,
   +-				  disk_str, inflate_str, NULL);
   +-
   +-		free(label_str);
   +-		free(nr_str);
   +-		free(disk_str);
   +-		free(inflate_str);
   +-	}
   +-
   +-	print_table_plaintext(&table);
   +-	clear_table(&table);
   +-}
   +-
   +-static void survey_report_plaintext_sorted_size(
   +-		struct survey_report_top_table *top)
   +-{
   +-	survey_report_object_sizes(top->name,  _("Path"),
   +-				   top->data, top->nr);
   +-}
   +-
   +-static void survey_report_plaintext(struct survey_context *ctx)
   +-{
   +-	printf("GIT SURVEY for \"%s\"\n", ctx->repo->worktree);
   +-	printf("-----------------------------------------------------\n");
   +-	survey_report_plaintext_refs(ctx);
   +-	survey_report_plaintext_reachable_object_summary(ctx);
   +-	survey_report_object_sizes(_("TOTAL OBJECT SIZES BY TYPE"),
   +-				   _("Object Type"),
   +-				   ctx->report.by_type,
   +-				   REPORT_TYPE_COUNT);
   +-
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_count[REPORT_TYPE_TREE]);
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_count[REPORT_TYPE_BLOB]);
   +-
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_disk[REPORT_TYPE_TREE]);
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_disk[REPORT_TYPE_BLOB]);
   +-
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_inflate[REPORT_TYPE_TREE]);
   +-	survey_report_plaintext_sorted_size(
   +-		&ctx->report.top_paths_by_inflate[REPORT_TYPE_BLOB]);
   +-}
   +-
   +-/*
   +- * After parsing the command line arguments, figure out which refs we
   +- * should scan.
   +- *
   +- * If ANY were given in positive sense, then we ONLY include them and
   +- * do not use the builtin values.
   +- */
   +-static void fixup_refs_wanted(struct survey_context *ctx)
   +-{
   +-	struct survey_refs_wanted *rw = &ctx->opts.refs;
   +-
   +-	/*
   +-	 * `--all-refs` overrides and enables everything.
   +-	 */
   +-	if (rw->want_all_refs == 1) {
   +-		rw->want_branches = 1;
   +-		rw->want_tags = 1;
   +-		rw->want_remotes = 1;
   +-		rw->want_detached = 1;
   +-		rw->want_other = 1;
   +-		return;
   +-	}
   +-
   +-	/*
   +-	 * If none of the `--<ref-type>` were given, we assume all
   +-	 * of the builtin unspecified values.
   +-	 */
   +-	if (rw->want_branches == -1 &&
   +-	    rw->want_tags == -1 &&
   +-	    rw->want_remotes == -1 &&
   +-	    rw->want_detached == -1 &&
   +-	    rw->want_other == -1) {
   +-		*rw = default_ref_options;
   +-		return;
   +-	}
   +-
   +-	/*
   +-	 * Since we only allow positive boolean values on the command
   +-	 * line, we will only have true values where they specified
   +-	 * a `--<ref-type>`.
   +-	 *
   +-	 * So anything that still has an unspecified value should be
   +-	 * set to false.
   +-	 */
   +-	if (rw->want_branches == -1)
   +-		rw->want_branches = 0;
   +-	if (rw->want_tags == -1)
   +-		rw->want_tags = 0;
   +-	if (rw->want_remotes == -1)
   +-		rw->want_remotes = 0;
   +-	if (rw->want_detached == -1)
   +-		rw->want_detached = 0;
   +-	if (rw->want_other == -1)
   +-		rw->want_other = 0;
   +-}
   +-
   +-static int survey_load_config_cb(const char *var, const char *value,
   +-				 const struct config_context *cctx, void *pvoid)
   +-{
   +-	struct survey_context *ctx = pvoid;
   +-
   +-	if (!strcmp(var, "survey.verbose")) {
   +-		ctx->opts.verbose = git_config_bool(var, value);
   +-		return 0;
   +-	}
   +-	if (!strcmp(var, "survey.progress")) {
   +-		ctx->opts.show_progress = git_config_bool(var, value);
   +-		return 0;
   +-	}
   +-	if (!strcmp(var, "survey.top")) {
   +-		ctx->opts.top_nr = git_config_bool(var, value);
   +-		return 0;
   +-	}
   +-
   +-	return git_default_config(var, value, cctx, pvoid);
   +-}
   +-
   +-static void survey_load_config(struct survey_context *ctx)
   +-{
   +-	repo_config(the_repository, survey_load_config_cb, ctx);
   +-}
   +-
   +-static void do_load_refs(struct survey_context *ctx,
   +-			 struct ref_array *ref_array)
   +-{
   +-	struct ref_filter filter = REF_FILTER_INIT;
   +-	struct ref_sorting *sorting;
   +-	struct string_list sorting_options = STRING_LIST_INIT_DUP;
   +-
   +-	string_list_append(&sorting_options, "objectname");
   +-	sorting = ref_sorting_options(&sorting_options);
   +-
   +-	if (ctx->opts.refs.want_detached)
   +-		strvec_push(&ctx->refs, "HEAD");
   +-
   +-	if (ctx->opts.refs.want_all_refs) {
   +-		strvec_push(&ctx->refs, "refs/");
   +-	} else {
   +-		if (ctx->opts.refs.want_branches)
   +-			strvec_push(&ctx->refs, "refs/heads/");
   +-		if (ctx->opts.refs.want_tags)
   +-			strvec_push(&ctx->refs, "refs/tags/");
   +-		if (ctx->opts.refs.want_remotes)
   +-			strvec_push(&ctx->refs, "refs/remotes/");
   +-		if (ctx->opts.refs.want_other) {
   +-			strvec_push(&ctx->refs, "refs/notes/");
   +-			strvec_push(&ctx->refs, "refs/stash/");
   +-		}
   +-	}
   +-
   +-	filter.name_patterns = ctx->refs.v;
   +-	filter.ignore_case = 0;
   +-	filter.match_as_path = 1;
   +-
   +-	if (ctx->opts.show_progress) {
   +-		ctx->progress_total = 0;
   +-		ctx->progress = start_progress(ctx->repo,
   +-					       _("Scanning refs..."), 0);
   +-	}
   +-
   +-	filter_refs(ref_array, &filter, FILTER_REFS_KIND_MASK);
   +-
   +-	if (ctx->opts.show_progress) {
   +-		ctx->progress_total = ref_array->nr;
   +-		display_progress(ctx->progress, ctx->progress_total);
   +-	}
   +-
   +-	ref_array_sort(sorting, ref_array);
   +-
   +-	stop_progress(&ctx->progress);
   +-	ref_filter_clear(&filter);
   +-	ref_sorting_release(sorting);
   +-}
   +-
   +-/*
   +- * The REFS phase:
   +- *
   +- * Load the set of requested refs and assess them for scalablity problems.
   +- * Use that set to start a treewalk to all reachable objects and assess
   +- * them.
   +- *
   +- * This data will give us insights into the repository itself (the number
   +- * of refs, the size and shape of the DAG, the number and size of the
   +- * objects).
   +- *
   +- * Theoretically, this data is independent of the on-disk representation
   +- * (e.g. independent of packing concerns).
   +- */
   +-static void survey_phase_refs(struct survey_context *ctx)
   +-{
   +-	trace2_region_enter("survey", "phase/refs", ctx->repo);
   +-	do_load_refs(ctx, &ctx->ref_array);
   +-
   +-	ctx->report.refs.refs_nr = ctx->ref_array.nr;
   +-	for (int i = 0; i < ctx->ref_array.nr; i++) {
   +-		size_t size;
   +-		struct ref_array_item *item = ctx->ref_array.items[i];
   +-
   +-		switch (item->kind) {
   +-		case FILTER_REFS_TAGS:
   +-			ctx->report.refs.tags_nr++;
   +-			if (odb_read_object_info(ctx->repo->objects,
   +-						 &item->objectname,
   +-						 &size) == OBJ_TAG)
   +-				ctx->report.refs.tags_annotated_nr++;
   +-			break;
   +-
   +-		case FILTER_REFS_BRANCHES:
   +-			ctx->report.refs.branches_nr++;
   +-			break;
   +-
   +-		case FILTER_REFS_REMOTES:
   +-			ctx->report.refs.remote_refs_nr++;
   +-			break;
   +-
   +-		case FILTER_REFS_OTHERS:
   +-			ctx->report.refs.others_nr++;
   +-			break;
   +-
   +-		default:
   +-			ctx->report.refs.unknown_nr++;
   +-			break;
   +-		}
   +-	}
   +-
   +-	trace2_region_leave("survey", "phase/refs", ctx->repo);
   +-}
   +-
   +-static void increment_object_counts(
   +-		struct survey_report_object_summary *summary,
   +-		enum object_type type,
   +-		size_t nr)
   +-{
   +-	switch (type) {
   +-	case OBJ_COMMIT:
   +-		summary->commits_nr += nr;
   +-		break;
   +-
   +-	case OBJ_TREE:
   +-		summary->trees_nr += nr;
   +-		break;
   +-
   +-	case OBJ_BLOB:
   +-		summary->blobs_nr += nr;
   +-		break;
   +-
   +-	case OBJ_TAG:
   +-		summary->tags_nr += nr;
   +-		break;
   +-
   +-	default:
   +-		break;
   +-	}
   +-}
   +-
   +-static void increment_totals(struct survey_context *ctx,
   +-			     struct oid_array *oids,
   +-			     struct survey_report_object_size_summary *summary)
   +-{
   +-	for (size_t i = 0; i < oids->nr; i++) {
   +-		struct object_info oi = OBJECT_INFO_INIT;
   +-		unsigned oi_flags = OBJECT_INFO_FOR_PREFETCH;
   +-		size_t object_length = 0;
   +-		off_t disk_sizep = 0;
   +-		enum object_type type;
   +-
   +-		oi.typep = &type;
   +-		oi.sizep = &object_length;
   +-		oi.disk_sizep = &disk_sizep;
   +-
   +-		if (odb_read_object_info_extended(ctx->repo->objects,
   +-						  &oids->oid[i],
   +-						  &oi, oi_flags) < 0) {
   +-			summary->num_missing++;
   +-		} else {
   +-			summary->nr++;
   +-			summary->disk_size += disk_sizep;
   +-			summary->inflated_size += object_length;
   +-		}
   +-	}
   +-}
   +-
   +-static void increment_object_totals(struct survey_context *ctx,
   +-				    struct oid_array *oids,
   +-				    enum object_type type,
   +-				    const char *path)
   +-{
   +-	struct survey_report_object_size_summary *total;
   +-	struct survey_report_object_size_summary summary = { 0 };
   +-
   +-	increment_totals(ctx, oids, &summary);
   +-
   +-	switch (type) {
   +-	case OBJ_COMMIT:
   +-		total = &ctx->report.by_type[REPORT_TYPE_COMMIT];
   +-		break;
   +-
   +-	case OBJ_TREE:
   +-		total = &ctx->report.by_type[REPORT_TYPE_TREE];
   +-		break;
   +-
   +-	case OBJ_BLOB:
   +-		total = &ctx->report.by_type[REPORT_TYPE_BLOB];
   +-		break;
   +-
   +-	case OBJ_TAG:
   +-		total = &ctx->report.by_type[REPORT_TYPE_TAG];
   +-		break;
   +-
   +-	default:
   +-		BUG("No other type allowed");
   +-	}
   +-
   +-	total->nr += summary.nr;
   +-	total->disk_size += summary.disk_size;
   +-	total->inflated_size += summary.inflated_size;
   +-	total->num_missing += summary.num_missing;
   +-
   +-	if (type == OBJ_TREE || type == OBJ_BLOB) {
   +-		int index = type == OBJ_TREE ?
   +-			    REPORT_TYPE_TREE : REPORT_TYPE_BLOB;
   +-		struct survey_report_top_table *top;
   +-
   +-		/*
   +-		 * Temporarily store (const char *) here, but it will
   +-		 * be duped if inserted and will not be freed.
   +-		 */
   +-		summary.label = (char *)path;
   +-
   +-		top = ctx->report.top_paths_by_count;
   +-		maybe_insert_into_top_size(&top[index], &summary);
   +-
   +-		top = ctx->report.top_paths_by_disk;
   +-		maybe_insert_into_top_size(&top[index], &summary);
   +-
   +-		top = ctx->report.top_paths_by_inflate;
   +-		maybe_insert_into_top_size(&top[index], &summary);
   +-	}
   +-}
   +-
   +-static int survey_objects_path_walk_fn(const char *path,
   +-				       struct oid_array *oids,
   +-				       enum object_type type,
   +-				       void *data)
   +-{
   +-	struct survey_context *ctx = data;
   +-
   +-	increment_object_counts(&ctx->report.reachable_objects,
   +-				type, oids->nr);
   +-	increment_object_totals(ctx, oids, type, path);
   +-
   +-	ctx->progress_nr += oids->nr;
   +-	display_progress(ctx->progress, ctx->progress_nr);
   +-
   +-	return 0;
   +-}
   +-
   +-static void initialize_report(struct survey_context *ctx)
   +-{
   +-	CALLOC_ARRAY(ctx->report.by_type, REPORT_TYPE_COUNT);
   +-	ctx->report.by_type[REPORT_TYPE_COMMIT].label = xstrdup(_("Commits"));
   +-	ctx->report.by_type[REPORT_TYPE_TREE].label = xstrdup(_("Trees"));
   +-	ctx->report.by_type[REPORT_TYPE_BLOB].label = xstrdup(_("Blobs"));
   +-	ctx->report.by_type[REPORT_TYPE_TAG].label = xstrdup(_("Tags"));
   +-
   +-	CALLOC_ARRAY(ctx->report.top_paths_by_count, REPORT_TYPE_COUNT);
   +-	init_top_sizes(&ctx->report.top_paths_by_count[REPORT_TYPE_TREE],
   +-		       ctx->opts.top_nr, _("TOP DIRECTORIES BY COUNT"), cmp_by_nr);
   +-	init_top_sizes(&ctx->report.top_paths_by_count[REPORT_TYPE_BLOB],
   +-		       ctx->opts.top_nr, _("TOP FILES BY COUNT"), cmp_by_nr);
   +-
   +-	CALLOC_ARRAY(ctx->report.top_paths_by_disk, REPORT_TYPE_COUNT);
   +-	init_top_sizes(&ctx->report.top_paths_by_disk[REPORT_TYPE_TREE],
   +-		       ctx->opts.top_nr, _("TOP DIRECTORIES BY DISK SIZE"), cmp_by_disk_size);
   +-	init_top_sizes(&ctx->report.top_paths_by_disk[REPORT_TYPE_BLOB],
   +-		       ctx->opts.top_nr, _("TOP FILES BY DISK SIZE"), cmp_by_disk_size);
   +-
   +-	CALLOC_ARRAY(ctx->report.top_paths_by_inflate, REPORT_TYPE_COUNT);
   +-	init_top_sizes(&ctx->report.top_paths_by_inflate[REPORT_TYPE_TREE],
   +-		       ctx->opts.top_nr, _("TOP DIRECTORIES BY INFLATED SIZE"), cmp_by_inflated_size);
   +-	init_top_sizes(&ctx->report.top_paths_by_inflate[REPORT_TYPE_BLOB],
   +-		       ctx->opts.top_nr, _("TOP FILES BY INFLATED SIZE"), cmp_by_inflated_size);
   +-}
   +-
   +-static void survey_phase_objects(struct survey_context *ctx)
   +-{
   +-	struct rev_info revs = REV_INFO_INIT;
   +-	struct path_walk_info info = PATH_WALK_INFO_INIT;
   +-	unsigned int add_flags = 0;
   +-
   +-	trace2_region_enter("survey", "phase/objects", ctx->repo);
   +-
   +-	info.revs = &revs;
   +-	info.path_fn = survey_objects_path_walk_fn;
   +-	info.path_fn_data = ctx;
   +-
   +-	initialize_report(ctx);
   +-
   +-	repo_init_revisions(ctx->repo, &revs, "");
   +-	revs.tag_objects = 1;
   +-
   +-	ctx->progress_nr = 0;
   +-	ctx->progress_total = ctx->ref_array.nr;
   +-	if (ctx->opts.show_progress)
   +-		ctx->progress = start_progress(ctx->repo,
   +-					       _("Preparing object walk"),
   +-					       ctx->progress_total);
   +-	for (int i = 0; i < ctx->ref_array.nr; i++) {
   +-		struct ref_array_item *item = ctx->ref_array.items[i];
   +-		add_pending_oid(&revs, NULL, &item->objectname, add_flags);
   +-		display_progress(ctx->progress, ++(ctx->progress_nr));
   +-	}
   +-	stop_progress(&ctx->progress);
   +-
   +-	ctx->progress_nr = 0;
   +-	ctx->progress_total = 0;
   +-	if (ctx->opts.show_progress)
   +-		ctx->progress = start_progress(ctx->repo,
   +-					       _("Walking objects"), 0);
   +-	walk_objects_by_path(&info);
   +-	stop_progress(&ctx->progress);
   +-
   +-	release_revisions(&revs);
   +-	trace2_region_leave("survey", "phase/objects", ctx->repo);
   +-}
   +-
   +-int cmd_survey(int argc, const char **argv, const char *prefix, struct repository *repo)
   +-{
   +-	static struct survey_context ctx = {
   +-		.opts = {
   +-			.verbose = 0,
   +-			.show_progress = -1, /* defaults to isatty(2) */
   +-			.top_nr = 10,
   +-
   +-			.refs.want_all_refs = -1,
   +-
   +-			.refs.want_branches = -1, /* default these to undefined */
   +-			.refs.want_tags = -1,
   +-			.refs.want_remotes = -1,
   +-			.refs.want_detached = -1,
   +-			.refs.want_other = -1,
   +-		},
   +-		.refs = STRVEC_INIT,
   +-	};
   +-
   +-	static struct option survey_options[] = {
   +-		OPT__VERBOSE(&ctx.opts.verbose, N_("verbose output")),
   +-		OPT_BOOL(0, "progress", &ctx.opts.show_progress, N_("show progress")),
   +-		OPT_INTEGER('n', "top", &ctx.opts.top_nr,
   +-			    N_("number of entries to include in detail tables")),
   +-
   +-		OPT_BOOL_F(0, "all-refs", &ctx.opts.refs.want_all_refs, N_("include all refs"),          PARSE_OPT_NONEG),
   +-
   +-		OPT_BOOL_F(0, "branches", &ctx.opts.refs.want_branches, N_("include branches"),          PARSE_OPT_NONEG),
   +-		OPT_BOOL_F(0, "tags",     &ctx.opts.refs.want_tags,     N_("include tags"),              PARSE_OPT_NONEG),
   +-		OPT_BOOL_F(0, "remotes",  &ctx.opts.refs.want_remotes,  N_("include all remotes refs"),  PARSE_OPT_NONEG),
   +-		OPT_BOOL_F(0, "detached", &ctx.opts.refs.want_detached, N_("include detached HEAD"),     PARSE_OPT_NONEG),
   +-		OPT_BOOL_F(0, "other",    &ctx.opts.refs.want_other,    N_("include notes and stashes"), PARSE_OPT_NONEG),
   +-
   +-		OPT_END(),
   +-	};
   +-
   +-	show_usage_with_options_if_asked(argc, argv,
   +-					 survey_usage, survey_options);
   +-
   +-	if (isatty(2))
   +-		color_fprintf_ln(stderr,
   +-				 want_color_fd(2, GIT_COLOR_AUTO) ? GIT_COLOR_YELLOW : "",
   +-				 "(THIS IS EXPERIMENTAL, EXPECT THE OUTPUT FORMAT TO CHANGE!)");
   +-
   +-	ctx.repo = repo;
   +-
   +-	prepare_repo_settings(ctx.repo);
   +-	survey_load_config(&ctx);
   +-
   +-	argc = parse_options(argc, argv, prefix, survey_options, survey_usage, 0);
   +-
   +-	if (ctx.opts.show_progress < 0)
   +-		ctx.opts.show_progress = isatty(2);
   +-
   +-	fixup_refs_wanted(&ctx);
   +-
   +-	survey_phase_refs(&ctx);
   +-
   +-	survey_phase_objects(&ctx);
   +-
   +-	survey_report_plaintext(&ctx);
   +-
   +-	clear_survey_context(&ctx);
   +-	return 0;
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + }
   +
   + ## ci/lib.sh ##
   + remerge CONFLICT (content): Merge conflict in ci/lib.sh
   + index c1212411e6..f31a36ceeb 100755
   + --- ci/lib.sh
   + +++ ci/lib.sh
   +@@ ci/lib.sh: export SKIP_DASHED_BUILT_INS=YesPlease
   + # In order to catch bugs introduced at integration time by mismerges,
   + # enable the long tests for pushes to the integration branches as well.
   + test -z "$MSYSTEM" ||
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + case "$CI_EVENT,$CI_BRANCH" in
   +-=======
   +-case "$GITHUB_EVENT_NAME,$CI_BRANCH" in
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + pull_request,*|push,*next*|push,*master*|push,*main*|push,*maint*)
   + 	export GIT_TEST_LONG=${GIT_TEST_LONG:-true}
   + 	;;
   +
   + ## compat/mingw.c ##
   + remerge CONFLICT (content): Merge conflict in compat/mingw.c
   + index 101afd00d0..df70bae6b6 100644
   + --- compat/mingw.c
   + +++ compat/mingw.c
   +@@ compat/mingw.c: static void setup_windows_environment(void)
   + 
   + 	if (!getenv("LC_ALL") && !getenv("LC_CTYPE") && !getenv("LANG"))
   + 		setenv("LC_CTYPE", "C.UTF-8", 1);
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + }
   + 
   + int mingw_platform_has_symlinks(void)
   + {
   + 	static int has_symlinks = -1;
   +-=======
   +-
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 	/*
   + 	 * Change 'core.symlinks' default to false, unless native symlinks are
   + 	 * enabled in MSys2 (via 'MSYS=winsymlinks:nativestrict'). Thus we can
   +
     ## compat/win32/path-utils.c ##
   + remerge CONFLICT (content): Merge conflict in compat/win32/path-utils.c
   + index ca11173457..6250de69cb 100644
   + --- compat/win32/path-utils.c
   + +++ compat/win32/path-utils.c
    @@
   + 
     #include "../../git-compat-util.h"
     #include "../../environment.h"
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
     #include "../../repository.h"
   -+#include "../../strbuf.h"
   -+#include "../../versioncmp.h"
   +-=======
   +-#include "../../wrapper.h"
   + #include "../../strbuf.h"
   + #include "../../versioncmp.h"
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
     
     int win32_has_dos_drive_prefix(const char *path)
     {
   -@@ compat/win32/path-utils.c: int win32_fspathcmp(const char *a, const char *b)
   - {
   - 	return win32_fspathncmp(a, b, (size_t)-1);
   +
   + ## object-file.c ##
   + remerge CONFLICT (content): Merge conflict in object-file.c
   + index fbd3892d72..a4cbf8b081 100644
   + --- object-file.c
   + +++ object-file.c
   +@@ object-file.c: int parse_loose_header(const char *hdr, struct object_info *oi)
   + 	return 0;
     }
   -+
   -+static int read_at(int fd, char *buffer, size_t offset, size_t size)
   -+{
   -+	if (lseek(fd, offset, SEEK_SET) < 0) {
   -+		fprintf(stderr, "could not seek to 0x%x\n", (unsigned int)offset);
   -+		return -1;
   -+	}
   -+
   -+	return read_in_full(fd, buffer, size);
   -+}
   -+
   -+static size_t le16(const char *buffer)
   -+{
   -+	unsigned char *u = (unsigned char *)buffer;
   -+	return u[0] | (u[1] << 8);
   -+}
   -+
   -+static size_t le32(const char *buffer)
   -+{
   -+	return le16(buffer) | (le16(buffer + 2) << 16);
   -+}
   -+
   -+/*
   -+ * Determine the Go version of a given executable, if it was built with Go.
   -+ *
   -+ * This recapitulates the logic from
   -+ * https://github.com/golang/go/blob/master/src/cmd/go/internal/version/version.go
   -+ * (without requiring the user to install `go.exe` to find out).
   -+ */
   -+static ssize_t get_go_version(const char *path, char *go_version, size_t go_version_size)
   -+{
   -+	int fd = open(path, O_RDONLY);
   -+	char buffer[1024];
   -+	off_t offset;
   -+	size_t num_sections, opt_header_size, i;
   -+	char *p = NULL, *q;
   -+	ssize_t res = -1;
   -+
   -+	if (fd < 0)
   -+		return -1;
   -+
   -+	if (read_in_full(fd, buffer, 2) < 0)
   -+		goto fail;
   -+
   -+	/*
   -+	 * Parse the PE file format, for more details, see
   -+	 * https://en.wikipedia.org/wiki/Portable_Executable#Layout and
   -+	 * https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
   -+	 */
   -+	if (buffer[0] != 'M' || buffer[1] != 'Z')
   -+		goto fail;
   -+
   -+	if (read_at(fd, buffer, 0x3c, 4) < 0)
   -+		goto fail;
   -+
   -+	/* Read the `PE\0\0` signature and the COFF file header */
   -+	offset = le32(buffer);
   -+	if (read_at(fd, buffer, offset, 24) < 0)
   -+		goto fail;
   -+
   -+	if (buffer[0] != 'P' || buffer[1] != 'E' || buffer[2] != '\0' || buffer[3] != '\0')
   -+		goto fail;
   -+
   -+	num_sections = le16(buffer + 6);
   -+	opt_header_size = le16(buffer + 20);
   -+	offset += 24; /* skip file header */
   -+
   -+	/*
   -+	 * Validate magic number 0x10b or 0x20b, for full details see
   -+	 * https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#optional-header-standard-fields-image-only
   -+	 */
   -+	if (read_at(fd, buffer, offset, 2) < 0 ||
   -+	    ((i = le16(buffer)) != 0x10b && i != 0x20b))
   -+		goto fail;
   -+
   -+	offset += opt_header_size;
   -+
   -+	for (i = 0; i < num_sections; i++) {
   -+		if (read_at(fd, buffer, offset + i * 40, 40) < 0)
   -+			goto fail;
   -+
   -+		/*
   -+		 * For full details about the section headers, see
   -+		 * https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-table-section-headers
   -+		 */
   -+		if ((le32(buffer + 36) /* characteristics */ & ~0x600000) /* IMAGE_SCN_ALIGN_32BYTES */ ==
   -+		    (/* IMAGE_SCN_CNT_INITIALIZED_DATA */ 0x00000040 |
   -+		     /* IMAGE_SCN_MEM_READ */ 0x40000000 |
   -+		     /* IMAGE_SCN_MEM_WRITE */ 0x80000000)) {
   -+			size_t size = le32(buffer + 16); /* "SizeOfRawData " */
   -+			size_t pointer = le32(buffer + 20); /* "PointerToRawData " */
   -+
   -+			/*
   -+			 * Skip the section if either size or pointer is 0, see
   -+			 * https://github.com/golang/go/blob/go1.21.0/src/debug/buildinfo/buildinfo.go#L333
   -+			 * for full details.
   -+			 *
   -+			 * Merely seeing a non-zero size will not actually do,
   -+			 * though: he size must be at least `buildInfoSize`,
   -+			 * i.e. 32, and we expect a UVarint (at least another
   -+			 * byte) _and_ the bytes representing the string,
   -+			 * which we expect to start with the letters "go" and
   -+			 * continue with the Go version number.
   -+			 */
   -+			if (size < 32 + 1 + 2 + 1 || !pointer)
   -+				continue;
   -+
   -+			p = malloc(size);
   -+
   -+			if (!p || read_at(fd, p, pointer, size) < 0)
   -+				goto fail;
   -+
   -+			/*
   -+			 * Look for the build information embedded by Go, see
   -+			 * https://github.com/golang/go/blob/go1.21.0/src/debug/buildinfo/buildinfo.go#L165-L175
   -+			 * for full details.
   -+			 *
   -+			 * Note: Go contains code to enforce alignment along a
   -+			 * 16-byte boundary. In practice, no `.exe` has been
   -+			 * observed that required any adjustment, therefore
   -+			 * this here code skips that logic for simplicity.
   -+			 */
   -+			q = memmem(p, size - 18, "\xff Go buildinf:", 14);
   -+			if (!q)
   -+				goto fail;
   -+			/*
   -+			 * Decode the build blob. For full details, see
   -+			 * https://github.com/golang/go/blob/go1.21.0/src/debug/buildinfo/buildinfo.go#L177-L191
   -+			 *
   -+			 * Note: The `endianness` values observed in practice
   -+			 * were always 2, therefore the complex logic to handle
   -+			 * any other value is skipped for simplicty.
   -+			 */
   -+			if ((q[14] == 8 || q[14] == 4) && q[15] == 2) {
   -+				/*
   -+				 * Only handle a Go version string with fewer
   -+				 * than 128 characters, so the Go UVarint at
   -+				 * q[32] that indicates the string's length must
   -+				 * be only one byte (without the high bit set).
   -+				 */
   -+				if ((q[32] & 0x80) ||
   -+				    !q[32] ||
   -+				    (q + 33 + q[32] - p) > (ssize_t)size ||
   -+				    q[32] + 1 > (ssize_t)go_version_size)
   -+					goto fail;
   -+				res = q[32];
   -+				memcpy(go_version, q + 33, res);
   -+				go_version[res] = '\0';
   -+				break;
   -+			}
   -+		}
   -+	}
   -+
   -+fail:
   -+	free(p);
   -+	close(fd);
   -+	return res;
   -+}
   -+
   -+void win32_warn_about_git_lfs_on_windows7(int exit_code, const char *argv0)
   -+{
   -+	char buffer[128], *git_lfs = NULL;
   -+	const char *p;
   -+
   -+	/*
   -+	 * Git LFS v3.5.1 fails with an Access Violation on Windows 7; That
   -+	 * would usually show up as an exit code 0xc0000005. For some reason
   -+	 * (probably because at this point, we no longer have the _original_
   -+	 * HANDLE that was returned by `CreateProcess()`) we observe other
   -+	 * values like 0xb00 and 0x2 instead. Since the exact exit code
   -+	 * seems to be inconsistent, we check for a non-zero exit status.
   -+	 */
   -+	if (exit_code == 0)
   -+		return;
   -+	if (GetVersion() >> 16 > 7601)
   -+		return; /* Warn only on Windows 7 or older */
   -+	if (!istarts_with(argv0, "git-lfs ") &&
   -+	    strcasecmp(argv0, "git-lfs"))
   -+		return;
   -+	if (!(git_lfs = locate_in_PATH("git-lfs")))
   -+		return;
   -+	if (get_go_version(git_lfs, buffer, sizeof(buffer)) > 0 &&
   -+	    skip_prefix(buffer, "go", &p) &&
   -+	    versioncmp("1.21.0", p) <= 0)
   -+		warning("This program was built with Go v%s\n"
   -+			"i.e. without support for this Windows version:\n"
   -+			"\n\t%s\n"
   -+			"\n"
   -+			"To work around this, you can download and install a "
   -+			"working version from\n"
   -+			"\n"
   -+			"\thttps://github.com/git-lfs/git-lfs/releases/tag/"
   -+			"v3.4.1\n",
   -+			p, git_lfs);
   -+	free(git_lfs);
   -+}
   + 
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   +-=======
   +-static void hash_object_body(const struct git_hash_algo *algo, struct git_hash_ctx *c,
   +-			     const void *buf, size_t len,
   +-			     struct object_id *oid,
   +-			     char *hdr, size_t *hdrlen)
   +-{
   +-	algo->init_fn(c);
   +-	git_hash_update(c, hdr, *hdrlen);
   +-	git_hash_update(c, buf, len);
   +-	git_hash_final_oid(oid, c);
   +-}
   +-
   +-void write_object_file_prepare(const struct git_hash_algo *algo,
   +-			       const void *buf, size_t len,
   +-			       enum object_type type, struct object_id *oid,
   +-			       char *hdr, size_t *hdrlen)
   +-{
   +-	struct git_hash_ctx c;
   +-
   +-	/* Generate the header */
   +-	*hdrlen = format_object_header(hdr, *hdrlen, type, len);
   +-
   +-	/* Hash (function pointers) computation */
   +-	hash_object_body(algo, &c, buf, len, oid, hdr, hdrlen);
   +-}
   +-
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + #define CHECK_COLLISION_DEST_VANISHED -2
   + 
   + static int check_collision(const char *source, const char *dest)
   +@@ object-file.c: void hash_object_file(const struct git_hash_algo *algo, const void *buf,
   + {
   + 	struct git_hash_ctx c;
   + 	char hdr[MAX_HEADER_LEN];
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	int hdrlen;
   +-=======
   +-	size_t hdrlen = sizeof(hdr);
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + 	hdrlen = format_object_header(hdr, sizeof(hdr), type, len);
   + 
    
   - ## compat/win32/path-utils.h ##
   -@@ compat/win32/path-utils.h: int win32_fspathcmp(const char *a, const char *b);
   - int win32_fspathncmp(const char *a, const char *b, size_t count);
   - #define fspathncmp win32_fspathncmp
   + ## object-file.h ##
   + remerge CONFLICT (content): Merge conflict in object-file.h
   + index 431081810b..f44758c4f8 100644
   + --- object-file.h
   + +++ object-file.h
   +@@ object-file.h: int finalize_object_file_flags(struct repository *repo,
   + void hash_object_file(const struct git_hash_algo *algo, const void *buf,
   + 		      size_t len, enum object_type type,
   + 		      struct object_id *oid);
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   +-=======
   +-void write_object_file_prepare(const struct git_hash_algo *algo,
   +-			       const void *buf, size_t len,
   +-			       enum object_type type, struct object_id *oid,
   +-			       char *hdr, size_t *hdrlen);
   +-int write_loose_object(struct odb_source_loose *loose,
   +-		       const struct object_id *oid, char *hdr,
   +-		       int hdrlen, const void *buf, unsigned long len,
   +-		       time_t mtime, unsigned flags);
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
     
   -+void win32_warn_about_git_lfs_on_windows7(int exit_code, const char *argv0);
   -+#define warn_about_git_lfs_on_windows7 win32_warn_about_git_lfs_on_windows7
   -+
   - #endif
   + /* Helper to check and "touch" a file */
   + int check_and_freshen_file(const char *fn, int freshen,
    
   - ## git-compat-util.h ##
   -@@ git-compat-util.h: static inline int git_offset_1st_component(const char *path)
   - #define fspathncmp git_fspathncmp
   - #endif
   - 
   -+#ifndef warn_about_git_lfs_on_windows7
   -+static inline void warn_about_git_lfs_on_windows7(int exit_code UNUSED,
   -+						  const char *argv0 UNUSED)
   -+{
   -+}
   -+#endif
   -+
   - #ifndef is_valid_path
   - #define is_valid_path(path) 1
   - #endif
   + ## odb/source-loose.c ##
   + remerge CONFLICT (content): Merge conflict in odb/source-loose.c
   + index ea0517eff0..524405445b 100644
   + --- odb/source-loose.c
   + +++ odb/source-loose.c
   +@@ odb/source-loose.c: static int write_loose_object(struct odb_source_loose *loose,
   + 
   + static int odb_source_loose_write_object(struct odb_source *source,
   + 					 const void *buf, size_t len,
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 					 enum object_type type,
   + 					 const struct object_id *oid,
   + 					 const struct object_id *compat_oid,
   + 					 const time_t *mtime,
   +-=======
   +-					 enum object_type type, struct object_id *oid,
   +-					 struct object_id *compat_oid_in,
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 					 enum odb_write_object_flags flags)
   + {
   + 	struct odb_source_loose *loose = odb_source_loose_downcast(source);
   + 	char hdr[MAX_HEADER_LEN];
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	int hdrlen;
   +-=======
   +-	size_t hdrlen = sizeof(hdr);
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + 	hdrlen = format_object_header(hdr, sizeof(hdr), type, len);
   + 
    
   - ## refs/reftable-backend.c ##
   -@@ refs/reftable-backend.c: static struct ref_store *reftable_be_init(struct repository *repo,
   + ## packfile.c ##
   + remerge CONFLICT (content): Merge conflict in packfile.c
   + index baa074adcb..4fa5fd67c8 100644
   + --- packfile.c
   + +++ packfile.c
   +@@ packfile.c: int unpack_object_header(struct packed_git *p,
   + 			 size_t *sizep)
   + {
   + 	unsigned char *base;
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	size_t left, used;
   +-=======
   +-	size_t left;
   +-	unsigned long used;
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 	enum object_type type;
     
   - 	reftable_set_alloc(malloc, realloc, free);
   + 	/* use_pack() assures us we have [base, base + 20) available
   +
   + ## setup.c ##
   + remerge CONFLICT (content): Merge conflict in setup.c
   + index c8e71bf970..e64afa9ced 100644
   + --- setup.c
   + +++ setup.c
   +@@ setup.c: int read_gitfile_raw(struct strbuf *contents, const char *path)
   + 		error_code = READ_GITFILE_ERR_NO_PATH;
   + 		goto cleanup_return;
   + 	}
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	strbuf_add(contents, buf+8, len-8);
   +-=======
   +-	buf[len] = '\0';
   +-	dir = buf + 8;
   +-
   +-	if (!is_absolute_path(dir) && (slash = strrchr(path, '/'))) {
   +-		size_t pathlen = slash+1 - path;
   +-		dir = xstrfmt("%.*s%.*s", (int)pathlen, path,
   +-			      (int)(len - 8), buf + 8);
   +-		free(buf);
   +-		buf = dir;
   +-	}
   +-#if (defined _WIN32 || defined __WIN32__)
   +-	if (is_dir_sep(dir[0]) && is_invalid_dotgit_path(path, dir)) {
   +-		strbuf_reset(&realpath);
   +-		strbuf_add(&realpath, dir, strlen(dir));
   +-		path = realpath.buf;
   +-		goto cleanup_return;
   +-	}
   +-#endif
   +-	if (!is_git_directory(dir)) {
   +-		error_code = READ_GITFILE_ERR_NOT_A_REPO;
   +-		goto cleanup_return;
   +-	}
   +-
   +-	strbuf_reset(&realpath);
   +-	strbuf_realpath(&realpath, dir, 1);
   +-	path = realpath.buf;
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
     
   -+	reftable_set_alloc(malloc, realloc, free);
   + cleanup_return:
   + 	free(buf);
   +
   + ## t/lib-bundle-uri-protocol.sh ##
   + remerge CONFLICT (content): Merge conflict in t/lib-bundle-uri-protocol.sh
   + index 2a81fda5e6..8a0f71df32 100644
   + --- t/lib-bundle-uri-protocol.sh
   + +++ t/lib-bundle-uri-protocol.sh
   +@@ t/lib-bundle-uri-protocol.sh: test_expect_success "test bundle-uri with $BUNDLE_URI_PROTOCOL:// using protocol
   + 	test_cmp_config_output expect actual
   + '
   + 
   +-<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + test_expect_success "test bundle-uri with $BUNDLE_URI_PROTOCOL:// using protocol v2 with empty value" '
   + 	test_config -C "$BUNDLE_URI_PARENT" \
   + 		bundle.bundle1.uri "$BUNDLE_URI_BUNDLE_URI_ESCAPED-1.bdl" &&
   +@@ t/lib-bundle-uri-protocol.sh: test_expect_success "test bundle-uri with $BUNDLE_URI_PROTOCOL:// using protocol
   + 	test_cmp_config_output expect actual
   + '
   + 
   +-=======
   +->>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
    +
   - 	refs_compute_filesystem_location(gitdir, payload, &is_worktree, &refdir,
   - 					 &ref_common_dir);
   + # Advertised bundle URIs are subject to protocol.*.allow; "file" (and bare or
   + # UNC paths) is denied by default, so such a URI must be skipped, not fetched.
   + advertise_uri () {
   +
   + ## t/t1517-outside-repo.sh ##
   + remerge CONFLICT (content): Merge conflict in t/t1517-outside-repo.sh
   + index 3a51526777..efbac29c0e 100755
   + --- t/t1517-outside-repo.sh
   + +++ t/t1517-outside-repo.sh
   +@@ t/t1517-outside-repo.sh: do
   + 	http-backend | http-fetch | http-push | init-db | \
   + 	mktag | p4 | p4.py | pickaxe | remote-ftp | remote-ftps | \
   + 	remote-http | remote-https | replay | send-email | \
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	sh-i18n--envsubst | shell | show | stage | survey | \
   + 	upload-archive--writer | upload-pack | whatchanged)
   + 		h_expect_outcome=expect_failure
   +@@ t/t1517-outside-repo.sh: do
   + 		h_expect_outcome=expect_success
   + 		all_expect_outcome=expect_failure
   + 		;;
   +-================================
   +-	sh-i18n--envsubst | shell | show | stage | submodule | survey | svn | \
   +-	upload-archive--writer | upload-pack | web--browse | whatchanged)
   +-		expect_outcome=expect_failure ;;
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 	*)
   + 		h_expect_outcome=expect_success
   + 		all_expect_outcome=expect_success
   +
   + ## t/t2031-checkout-long-paths.sh ##
   + remerge CONFLICT (add/add): Merge conflict in t/t2031-checkout-long-paths.sh
   + index 8a2c4ee880..4278a602cb 100755
   + --- t/t2031-checkout-long-paths.sh
   + +++ t/t2031-checkout-long-paths.sh
   +@@ t/t2031-checkout-long-paths.sh: test_expect_success setup '
   + test_expect_success 'checkout of long paths without core.longpaths fails' '
   + 	git config core.longpaths false &&
   + 	test_must_fail git checkout -f 2>error &&
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	test_grep -q "Filename too long" error &&
   +-================================
   +-	grep -q "Filename too long" error &&
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 	test ! -d longpa*
   + '
   + 
   +@@ t/t2031-checkout-long-paths.sh: test_expect_success SYMLINKS_WINDOWS 'leave drive-less, short paths intact' '
   + 	git update-index --add --cacheinfo 120000,$symlink_target_oid,PF &&
   + 	git -c core.symlinks=true checkout -- PF &&
   + 	cmd //c dir >actual &&
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	test_grep "<SYMLINKD\\?> *PF *\\[\\\\Program Files\\]" actual
   +-================================
   +-	grep "<SYMLINKD\\?> *PF *\\[\\\\Program Files\\]" actual
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + '
     
   + test_done
    
   - ## run-command.c ##
   -@@ run-command.c: static int wait_or_whine(pid_t pid, const char *argv0, int in_signal)
   - 		 */
   - 		code += 128;
   - 	} else if (WIFEXITED(status)) {
   -+		warn_about_git_lfs_on_windows7(status, argv0);
   - 		code = WEXITSTATUS(status);
   - 	} else {
   - 		if (!in_signal)
   + ## t/t6403-merge-file.sh ##
   + remerge CONFLICT (content): Merge conflict in t/t6403-merge-file.sh
   + index ecc681712e..bd58e471bc 100755
   + --- t/t6403-merge-file.sh
   + +++ t/t6403-merge-file.sh
   +@@ t/t6403-merge-file.sh: test_expect_success "expected conflict markers" '
   + test_expect_success 'binary files cannot be merged' '
   + 	test_must_fail git merge-file -p \
   + 		orig.txt "$TEST_DIRECTORY"/lib-diff/test-binary-1.png new1.txt 2> merge.err &&
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + 	test_grep "Cannot merge binary files" merge.err
   +-================================
   +-	grep "Cannot merge binary files" merge.err
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + '
   + 
   + test_expect_success 'binary files cannot be merged with --object-id' '
    
   - ## t/t7502-commit-porcelain.sh ##
   -@@ t/t7502-commit-porcelain.sh: test_expect_success 'cleanup commit messages (scissors option,-F,-e, scissors on
   - 	test_must_be_empty actual
   + ## t/t8100-git-survey.sh ##
   + remerge CONFLICT (add/add): Merge conflict in t/t8100-git-survey.sh
   + index ebf4cae9a6..a69d8f2672 100755
   + --- t/t8100-git-survey.sh
   + +++ t/t8100-git-survey.sh
   +@@
   + #!/bin/sh
   + 
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + test_description='git survey (deprecated shim over `git repo structure`)'
   +-================================
   +-test_description='git survey'
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + 
   + GIT_TEST_DEFAULT_INITIAL_BRANCH_NAME=main
   + export GIT_TEST_DEFAULT_INITIAL_BRANCH_NAME
   +@@ t/t8100-git-survey.sh: export TEST_PASSES_SANITIZE_LEAK
   + 
   + . ./test-lib.sh
   + 
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + test_expect_success 'git survey -h shows the deprecated banner' '
   + 	test_expect_code 0 git survey -h >usage &&
   + 	test_grep "DEPRECATED!" usage
   +-================================
   +-test_expect_success 'git survey -h shows experimental warning' '
   +-	test_expect_code 129 git survey -h >usage &&
   +-	grep "EXPERIMENTAL!" usage
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
     '
     
   -+test_expect_success 'helper-editor' '
   -+
   -+	write_script lf-to-crlf.sh <<-\EOF
   -+	sed "s/\$/Q/" <"$1" | tr Q "\\015" >"$1".new &&
   -+	mv -f "$1".new "$1"
   -+	EOF
   -+'
   -+
   -+test_expect_success 'cleanup commit messages (scissors option,-F,-e, CR/LF line endings)' '
   -+
   -+	test_config core.editor "\"$PWD/lf-to-crlf.sh\"" &&
   -+	scissors="# ------------------------ >8 ------------------------" &&
   -+
   -+	test_write_lines >text \
   -+	"# Keep this comment" "" " $scissors" \
   -+	"# Keep this comment, too" "$scissors" \
   -+	"# Remove this comment" "$scissors" \
   -+	"Remove this comment, too" &&
   -+
   -+	test_write_lines >expect \
   -+	"# Keep this comment" "" " $scissors" \
   -+	"# Keep this comment, too" &&
   -+
   -+	git commit --cleanup=scissors -e -F text --allow-empty &&
   -+	git cat-file -p HEAD >raw &&
   -+	sed -e "1,/^\$/d" raw >actual &&
   -+	test_cmp expect actual
   -+'
   -+
   -+test_expect_success 'cleanup commit messages (scissors option,-F,-e, scissors on first line, CR/LF line endings)' '
   -+
   -+	scissors="# ------------------------ >8 ------------------------" &&
   -+	test_write_lines >text \
   -+	"$scissors" \
   -+	"# Remove this comment and any following lines" &&
   -+	cp text /tmp/test2-text &&
   -+	git commit --cleanup=scissors -e -F text --allow-empty --allow-empty-message &&
   -+	git cat-file -p HEAD >raw &&
   -+	sed -e "1,/^\$/d" raw >actual &&
   -+	test_must_be_empty actual
   -+'
   -+
   - test_expect_success 'cleanup commit messages (strip option,-F)' '
   + test_expect_success 'create a semi-interesting repo' '
   +@@ t/t8100-git-survey.sh: test_expect_success 'create a semi-interesting repo' '
   + 	git update-ref -d refs/tags/two
   + '
   + 
   +-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 6aa2c2b208 (fixup??? survey: stub in new experimental 'git-survey' command)
   + test_expect_success 'survey prints a deprecation warning' '
   + 	git survey --all-refs >out 2>err &&
   + 	test_grep "is deprecated" err
   +@@ t/t8100-git-survey.sh: test_expect_success 'survey --branches translates to a refs/heads/* filter' '
   + 	git repo structure --top=10 \
   + 		--ref-filter="refs/heads/*" >expected &&
   + 	test_cmp expected out
   +-================================
   +-test_expect_success 'git survey --progress' '
   +-	GIT_PROGRESS_DELAY=0 git survey --all-refs --progress >out 2>err &&
   +-	grep "Preparing object walk" err
   +-'
   +-
   +-approximate_sizes() {
   +-	# very simplistic approximate rounding
   +-	sed -Ee "s/  *(1[0-9][0-9])( |$)/ ~0.1kB\2/g" \
   +-	  -e "s/  *(4[6-9][0-9]|5[0-6][0-9])( |$)/ ~0.5kB\2/g" \
   +-	  -e "s/  *(5[6-9][0-9]|6[0-6][0-9])( |$)/ ~0.6kB\2/g" \
   +-	  -e "s/  *1(4[89][0-9]|5[0-8][0-9])( |$)/ ~1.5kB\2/g" \
   +-	  -e "s/  *1(69[0-9]|7[0-9][0-9])( |$)/ ~1.7kB\2/g" \
   +-	  -e "s/  *1(79[0-9]|8[0-9][0-9])( |$)/ ~1.8kB\2/g" \
   +-	  -e "s/  *2(1[0-9][0-9]|20[0-1])( |$)/ ~2.1kB\2/g" \
   +-	  -e "s/  *2(3[0-9][0-9]|4[0-1][0-9])( |$)/ ~2.3kB\2/g" \
   +-	  -e "s/  *2(5[0-9][0-9]|6[0-1][0-9])( |$)/ ~2.5kB\2/g" \
   +-	 "$@"
   +-}
   +-
   +-test_expect_success 'git survey (default)' '
   +-	git survey --all-refs >out 2>err &&
   +-	test_line_count = 0 err &&
   +-
   +-	test_oid_cache <<-EOF &&
   +-	commits_sizes sha1:~1.5kB | ~2.1kB
   +-	commits_sizes sha256:~1.8kB | ~2.5kB
   +-	trees_sizes sha1:~0.5kB | ~1.7kB
   +-	trees_sizes sha256:~0.6kB | ~2.3kB
   +-	blobs_sizes sha1:~0.1kB | ~0.1kB
   +-	blobs_sizes sha256:~0.1kB | ~0.1kB
   +-	tags_sizes sha1:~0.5kB | ~0.5kB
   +-	tags_sizes sha256:~0.5kB | ~0.6kB
   +-	EOF
   +-
   +-	tr , " " >expect <<-EOF &&
   +-	GIT SURVEY for "$(pwd)"
   +-	-----------------------------------------------------
   +-
   +-	REFERENCES SUMMARY
   +-	========================
   +-	,       Ref Type | Count
   +-	-----------------+------
   +-	,       Branches |     1
   +-	     Remote refs |     0
   +-	      Tags (all) |     2
   +-	Tags (annotated) |     2
   +-
   +-	REACHABLE OBJECT SUMMARY
   +-	========================
   +-	Object Type | Count
   +-	------------+------
   +-	       Tags |     4
   +-	    Commits |    10
   +-	      Trees |    10
   +-	      Blobs |    10
   +-
   +-	TOTAL OBJECT SIZES BY TYPE
   +-	===============================================
   +-	Object Type | Count | Disk Size | Inflated Size
   +-	------------+-------+-----------+--------------
   +-	    Commits |    10 | $(test_oid commits_sizes)
   +-	      Trees |    10 | $(test_oid trees_sizes)
   +-	      Blobs |    10 | $(test_oid blobs_sizes)
   +-	       Tags |     4 | $(test_oid tags_sizes)
   +-	EOF
   +-
   +-	approximate_sizes out >out-edited &&
   +-	lines=$(wc -l <expect) &&
   +-	head -n "$lines" <out-edited >out-trimmed &&
   +-	test_cmp expect out-trimmed &&
   +-
   +-	for type in "DIRECTORIES" "FILES"
   +-	do
   +-		for metric in "COUNT" "DISK SIZE" "INFLATED SIZE"
   +-		do
   +-			grep "TOP $type BY $metric" out || return 1
   +-		done || return 1
   +-	done
   +->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 32c4f76892 (git-for-windows: prepare for 2.55.0(5))
   + '
     
   - 	echo >>negative &&
   + test_done
   ``````

</details>


#### BUILD FAILED: bb68782fd3 (Support loose 4GB+ objects (#6353), 2026-08-31)

Build failed after conflict resolution. Last 50 lines:

```
    CC builtin/help.o
    CC object-file.o
    CC odb.o
    CC odb/source.o
    CC odb/source-files.o
object-file.c: In function ‘close_loose_object’:
object-file.c:591:17: warning: implicit declaration of function ‘fsync_loose_object_transaction’; did you mean ‘flush_loose_object_transaction’? [-Wimplicit-function-declaration]
  591 |                 fsync_loose_object_transaction(loose->base.odb->transaction, fd, filename);
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                 flush_loose_object_transaction
object-file.c: In function ‘write_loose_object’:
object-file.c:770:17: warning: implicit declaration of function ‘prepare_loose_object_transaction’; did you mean ‘flush_loose_object_transaction’? [-Wimplicit-function-declaration]
  770 |                 prepare_loose_object_transaction(loose->base.odb->transaction);
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                 flush_loose_object_transaction
object-file.c: At top level:
object-file.c:817:42: warning: ‘struct odb_write_stream’ declared inside parameter list will not be visible outside of this definition or declaration
  817 |                                   struct odb_write_stream *in_stream, size_t len,
      |                                          ^~~~~~~~~~~~~~~~
object-file.c: In function ‘odb_source_loose_write_stream’:
object-file.c:860:51: error: invalid use of undefined type ‘struct odb_write_stream’
  860 |                 if (!stream.avail_in && !in_stream->is_finished) {
      |                                                   ^~
object-file.c:861:44: warning: implicit declaration of function ‘odb_write_stream_read’; did you mean ‘odb_stream_read’? [-Wimplicit-function-declaration]
  861 |                         ssize_t read_len = odb_write_stream_read(in_stream, buf,
      |                                            ^~~~~~~~~~~~~~~~~~~~~
      |                                            odb_stream_read
object-file.c:873:38: error: invalid use of undefined type ‘struct odb_write_stream’
  873 |                         if (in_stream->is_finished)
      |                                      ^~
object-file.c: At top level:
object-file.c:551:13: warning: ‘flush_loose_object_transaction’ defined but not used [-Wunused-function]
  551 | static void flush_loose_object_transaction(struct odb_transaction_files *transaction)
      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
make: *** [Makefile:2962: object-file.o] Error 1
make: *** Waiting for unfinished jobs....
```

