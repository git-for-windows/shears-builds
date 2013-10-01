#ifndef FSCACHE_H
#define FSCACHE_H

int fscache_enable(int enable);
#define enable_fscache(x) fscache_enable(x)

void flush_fscache(void);

DIR *fscache_opendir(const char *dir);
int fscache_lstat(const char *file_name, struct stat *buf);

#endif
