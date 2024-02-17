#ifndef ARENA_H_
#define ARENA_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
	size_t capacity;
	size_t size;
	char *mem;
} Arena;

Arena arena_init(size_t capacity);
char *arena_alloc(Arena *arena, size_t alloc_size);
void arena_reset(Arena *arena);
void arena_free(Arena *arena);

#endif
