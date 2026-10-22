#include "git-compat-util.h"
#include "gettext.h"
#include "object-file.h"
#include "odb/source-files.h"
#include "odb/source.h"
#include "packfile.h"

static const char * const odb_source_names_by_type[] = {
	[ODB_SOURCE_UNKNOWN] = "unknown",
	[ODB_SOURCE_FILES] = "files",
	[ODB_SOURCE_LOOSE] = "loose",
	[ODB_SOURCE_PACKED] = "packed",
	[ODB_SOURCE_INMEMORY] = "in-memory",
};

const char *odb_source_type_to_name(enum odb_source_type type)
{
	const char *name;
	if (type < 0 || type >= ARRAY_SIZE(odb_source_names_by_type))
		type = ODB_SOURCE_UNKNOWN;
	name = odb_source_names_by_type[type];
	if (!name)
		BUG("name missing in `odb_source_names_by_type` for '%d'", type);
	return name;
}

static enum odb_source_type odb_source_type_by_name(const char *name)
{
	if (!strcmp(name, "files"))
		return ODB_SOURCE_FILES;
	return ODB_SOURCE_UNKNOWN;
}

enum odb_source_type odb_source_type_by_uri(const char *uri, char **payload)
{
	enum odb_source_type type;
	const char *schema_end;
	char *name;

	schema_end = strstr(uri, "://");
	if (!schema_end) {
		name = xstrdup(uri);
		if (payload)
			*payload = NULL;
	} else {
		name = xstrndup(uri, schema_end - uri);
		if (payload)
			*payload = *(schema_end + 3) ? xstrdup(schema_end + 3) : NULL;
	}

	type = odb_source_type_by_name(name);
	free(name);
	return type;
}

struct odb_source *odb_source_new(struct object_database *odb,
				  const char *object_storage_format,
				  enum odb_new_flags flags)
{
	struct odb_source *source;
	char *payload = NULL;

	switch (odb_source_type_by_uri(object_storage_format, &payload)) {
	case ODB_SOURCE_FILES:
		source = &odb_source_files_new(odb, payload, flags)->base;
		break;
	default:
		die(_("unknown object storage format '%s'"), object_storage_format);
	}

	free(payload);
	return source;
}

void odb_source_init(struct odb_source *source,
		     struct object_database *odb,
		     enum odb_source_type type,
		     const char *path)
{
	source->odb = odb;
	source->type = type;
	source->path = xstrdup(path);
}

void odb_source_free(struct odb_source *source)
{
	if (!source)
		return;
	source->free(source);
}

void odb_source_release(struct odb_source *source)
{
	if (!source)
		return;
	free(source->path);
}
