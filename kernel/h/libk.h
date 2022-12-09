#ifndef LIBK_H
#define LIBK_H

#include <stddef.h>

void *memmove(void *d, const void *s, size_t size);
void *memset(void *buf, int value, size_t size);
char *strcat(char *d, const char *s);
char *strcpy(char *d, const char *s);
size_t strlen(const char *str);
int isdigit(char c);

#endif

