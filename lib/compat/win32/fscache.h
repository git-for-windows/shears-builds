#ifndef FSCACHE_H
#define FSCACHE_H

int fscache_enable(int enable);
#define enable_fscache(x) fscache_enable(x)

void fscache_flush(void);
#define flush_fscache() fscache_flush()

int fscache_is_enabled(void);
#define is_fscache_enabled() (fscache_is_enabled())

DIR *fscache_opendir(const char *dir);
int fscache_lstat(const char *file_name, struct stat *buf);

#endif
