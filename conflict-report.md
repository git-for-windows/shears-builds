## Rebase Summary: next

**From**: [20a0cd0e51](https://github.com/git-for-windows/git/commit/20a0cd0e518d0f6cf476b9b6f53625c515f41d2b) (Merge tag 'v2.55.0.windows.5', 2026-08-21) ([4d815612a2..20a0cd0e51](https://github.com/git-for-windows/git/compare/4d815612a22031cb8f7c1e48027dd0f4737cb60c...20a0cd0e518d0f6cf476b9b6f53625c515f41d2b))

#### BUILD FAILED: 20a0cd0e51 (Merge tag 'v2.55.0.windows.5', 2026-08-21)

Build failed after conflict resolution. Last 50 lines:

```
    CC editor.o
    CC entry.o
    CC environment.o
    CC ewah/bitmap.o
    CC ewah/ewah_bitmap.o
    CC ewah/ewah_io.o
    CC ewah/ewah_rlw.o
    CC exec-cmd.o
    CC fetch-negotiator.o
    CC fetch-object-info.o
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
    CC log-tree.o
    CC loose.o
    CC match-trees.o
    CC merge-ort.o
    CC midx-write.o
    CC notes-cache.o
    CC notes-merge.o
    CC notes.o
    CC object-file.o
    CC object.o
    CC odb.o
    CC odb/source.o
    CC odb/source-files.o
    CC odb/source-inmemory.o
    CC odb/source-loose.o
odb/source-loose.c:770:12: error: static declaration of ‘write_loose_object’ follows non-static declaration
  770 | static int write_loose_object(struct odb_source_loose *loose,
      |            ^~~~~~~~~~~~~~~~~~
In file included from odb/source-loose.c:7:
./object-file.h:124:5: note: previous declaration of ‘write_loose_object’ with type ‘int(struct odb_source_loose *, const struct object_id *, char *, int,  const void *, long unsigned int,  const time_t *, unsigned int)’ {aka ‘int(struct odb_source_loose *, const struct object_id *, char *, int,  const void *, long unsigned int,  const long int *, unsigned int)’}
  124 | int write_loose_object(struct odb_source_loose *loose,
      |     ^~~~~~~~~~~~~~~~~~
make: *** [Makefile:2962: odb/source-loose.o] Error 1
make: *** Waiting for unfinished jobs....
```

