## Rebase Summary: seen

**From**: [1df181dd99](https://github.com/git-for-windows/git/commit/1df181dd993a58f5d6b468f9955d48946932f4ea) (compat/poll: load user32 only when poll() runs (#6512), 2026-11-13) ([565c0b4b19..1df181dd99](https://github.com/git-for-windows/git/compare/565c0b4b19edc35d0fa76a1f38c9b5664c95d2cc...1df181dd993a58f5d6b468f9955d48946932f4ea))

#### BUILD FAILED: 504623f88a (Merge pull request #1897 from piscisaureus/symlink-attr, 2018-10-31)

Build failed after conflict resolution. Last 50 lines:

```
    CC builtin/init-db.o
    CC builtin/interpret-trailers.o
    CC builtin/last-modified.o
    CC builtin/log.o
    CC builtin/ls-files.o
    CC builtin/ls-remote.o
    CC builtin/ls-tree.o
    CC builtin/mailinfo.o
    CC builtin/mailsplit.o
    CC builtin/merge-base.o
    CC builtin/merge-file.o
    CC builtin/merge-index.o
    CC builtin/merge-ours.o
    CC builtin/merge-recursive.o
    CC builtin/merge-tree.o
    CC builtin/merge.o
    CC builtin/mktag.o
    CC builtin/mktree.o
    CC builtin/multi-pack-index.o
    CC builtin/mv.o
    CC builtin/name-rev.o
    CC builtin/notes.o
    CC builtin/pack-objects.o
    CC builtin/pack-redundant.o
    CC builtin/pack-refs.o
    CC builtin/patch-id.o
    CC builtin/prune-packed.o
    CC builtin/prune.o
    CC builtin/pull.o
    CC builtin/push.o
    CC builtin/range-diff.o
    CC builtin/read-tree.o
    CC builtin/rebase.o
    CC builtin/receive-pack.o
    CC builtin/reflog.o
    CC builtin/refs.o
    CC builtin/remote-ext.o
    CC builtin/remote-fd.o
    CC builtin/remote.o
    CC builtin/repack.o
    CC builtin/replace.o
    CC builtin/replay.o
    CC builtin/repo.o
builtin/repo.c: In function ‘cmd_repo_structure’:
builtin/repo.c:1069:54: error: ‘top_nr’ undeclared (first use in this function)
 1069 |         repo_config(repo, repo_structure_config_cb, &top_nr);
      |                                                      ^~~~~~
builtin/repo.c:1069:54: note: each undeclared identifier is reported only once for each function it appears in
make: *** [Makefile:2971: builtin/repo.o] Error 1
make: *** Waiting for unfinished jobs....
```

