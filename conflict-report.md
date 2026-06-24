## Rebase Summary: main

**From**: [31048fe70e](https://github.com/git-for-windows/git/commit/31048fe70ee87c7162fd048aeb8f7154564d334f) (Continue improving support for 4GB+ packs/clones/objects (#6289), 2026-06-23) ([bd4d1720b1..31048fe70e](https://github.com/git-for-windows/git/compare/bd4d1720b1871322e49b9d06135bcf717d5b1775...31048fe70ee87c7162fd048aeb8f7154564d334f))

#### BUILD FAILED: f8083c803c (Merge branch 'size-t/pack-objects-delta', 2026-06-07)

Build failed after conflict resolution. Last 50 lines:

```
  140 | int write_loose_object(struct odb_source_loose *loose,
      |     ^~~~~~~~~~~~~~~~~~
object-file.c:1060:5: error: conflicting types for ‘odb_source_loose_write_stream’; have ‘int(struct odb_source *, struct odb_write_stream *, size_t,  struct object_id *)’ {aka ‘int(struct odb_source *, struct odb_write_stream *, long unsigned int,  struct object_id *)’}
 1060 | int odb_source_loose_write_stream(struct odb_source *source,
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
object-file.h:36:5: note: previous declaration of ‘odb_source_loose_write_stream’ with type ‘int(struct odb_source_loose *, struct odb_write_stream *, size_t,  struct object_id *)’ {aka ‘int(struct odb_source_loose *, struct odb_write_stream *, long unsigned int,  struct object_id *)’}
   36 | int odb_source_loose_write_stream(struct odb_source_loose *source,
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
object-file.c: In function ‘odb_source_loose_write_stream’:
object-file.c:1172:49: warning: passing argument 1 of ‘repo_add_loose_object_map’ from incompatible pointer type [-Wincompatible-pointer-types]
 1172 |                 err = repo_add_loose_object_map(source, oid, &compat_oid);
      |                                                 ^~~~~~
      |                                                 |
      |                                                 struct odb_source *
In file included from object-file.c:19:
loose.h:20:56: note: expected ‘struct odb_source_loose *’ but argument is of type ‘struct odb_source *’
   20 | int repo_add_loose_object_map(struct odb_source_loose *loose,
      |                               ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
object-file.c: In function ‘odb_source_loose_write_object’:
object-file.c:1216:50: warning: passing argument 1 of ‘repo_add_loose_object_map’ from incompatible pointer type [-Wincompatible-pointer-types]
 1216 |                 return repo_add_loose_object_map(source, oid, &compat_oid);
      |                                                  ^~~~~~
      |                                                  |
      |                                                  struct odb_source *
loose.h:20:56: note: expected ‘struct odb_source_loose *’ but argument is of type ‘struct odb_source *’
   20 | int repo_add_loose_object_map(struct odb_source_loose *loose,
      |                               ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
object-file.c: In function ‘force_object_loose’:
object-file.c:1250:49: warning: passing argument 1 of ‘repo_add_loose_object_map’ from incompatible pointer type [-Wincompatible-pointer-types]
 1250 |                 ret = repo_add_loose_object_map(source, oid, &compat_oid);
      |                                                 ^~~~~~
      |                                                 |
      |                                                 struct odb_source *
loose.h:20:56: note: expected ‘struct odb_source_loose *’ but argument is of type ‘struct odb_source *’
   20 | int repo_add_loose_object_map(struct odb_source_loose *loose,
      |                               ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
    CC odb/source-inmemory.o
object-file.c: In function ‘stream_blob_to_pack’:
object-file.c:1469:30: error: ‘pack_compression_level’ undeclared (first use in this function)
 1469 |         git_deflate_init(&s, pack_compression_level);
      |                              ^~~~~~~~~~~~~~~~~~~~~~
object-file.c: At top level:
object-file.c:1744:12: error: static declaration of ‘for_each_file_in_obj_subdir’ follows non-static declaration
 1744 | static int for_each_file_in_obj_subdir(unsigned int subdir_nr,
      |            ^~~~~~~~~~~~~~~~~~~~~~~~~~~
object-file.h:84:5: note: previous declaration of ‘for_each_file_in_obj_subdir’ with type ‘int(unsigned int,  struct strbuf *, const struct git_hash_algo *, int (*)(const struct object_id *, const char *, void *), int (*)(const char *, const char *, void *), int (*)(unsigned int,  const char *, void *), void *)’
   84 | int for_each_file_in_obj_subdir(unsigned int subdir_nr,
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
make: *** [Makefile:2943: object-file.o] Error 1
make: *** Waiting for unfinished jobs....
```

