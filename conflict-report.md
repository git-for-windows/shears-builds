## Rebase Summary: main

**From**: [b83e3389b2](https://github.com/git-for-windows/git/commit/b83e3389b26a3cb36f4cfa465a71b1f8f4f91d5c) (Re-enable expensive tests in Windows CI (#6281), 2026-06-16) ([03412da7e1..b83e3389b2](https://github.com/git-for-windows/git/compare/03412da7e196f266307cc28a357b5cca0e5bea28...b83e3389b26a3cb36f4cfa465a71b1f8f4f91d5c))

#### BUILD FAILED: b06b1b85e5 (Merge 'objects-larger-than-4gb-on-windows-pt2', 2026-06-12)

Build failed after conflict resolution. Last 50 lines:

```
    CC exec-cmd.o
    CC fetch-negotiator.o
    CC fetch-pack.o
    CC fmt-merge-msg.o
    CC fsck.o
    CC fsmonitor.o
    CC fsmonitor-ipc.o
    CC fsmonitor-settings.o
    CC gettext.o
    CC git-zlib.o
    CC gpg-interface.o
    CC graph.o
    CC grep.o
    CC hash-lookup.o
    CC hash.o
    CC hashmap.o
    CC help.o
    CC hook.o
    CC object-file.o
    CC odb/source.o
    CC odb/source-files.o
object-file.c: In function ‘read_object_info_from_path’:
object-file.c:347:31: warning: implicit declaration of function ‘quick_has_loose’ [-Wimplicit-function-declaration]
  347 |                         ret = quick_has_loose(files->loose, oid) ? 0 : -1;
      |                               ^~~~~~~~~~~~~~~
    CC odb/source-inmemory.o
object-file.c: In function ‘odb_source_loose_read_object_info’:
object-file.c:478:24: warning: passing argument 1 of ‘odb_loose_path’ from incompatible pointer type [-Wincompatible-pointer-types]
  478 |         odb_loose_path(source, &buf, oid);
      |                        ^~~~~~
      |                        |
      |                        struct odb_source *
object-file.c:57:53: note: expected ‘struct odb_source_loose *’ but argument is of type ‘struct odb_source *’
   57 | const char *odb_loose_path(struct odb_source_loose *loose,
      |                            ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
object-file.c: At top level:
object-file.c:1862:26: error: conflicting types for ‘odb_source_loose_new’; have ‘struct odb_source_loose *(struct odb_source *)’
 1862 | struct odb_source_loose *odb_source_loose_new(struct odb_source *source)
      |                          ^~~~~~~~~~~~~~~~~~~~
In file included from object-file.h:7,
                 from object-file.c:21:
odb/source-loose.h:33:26: note: previous declaration of ‘odb_source_loose_new’ with type ‘struct odb_source_loose *(struct object_database *, const char *, _Bool)’
   33 | struct odb_source_loose *odb_source_loose_new(struct object_database *odb,
      |                          ^~~~~~~~~~~~~~~~~~~~
object-file.c: In function ‘odb_source_loose_new’:
object-file.c:1866:14: error: ‘struct odb_source_loose’ has no member named ‘source’
 1866 |         loose->source = source;
      |              ^~
make: *** [Makefile:2943: object-file.o] Error 1
make: *** Waiting for unfinished jobs....
```

