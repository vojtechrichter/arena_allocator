#ifndef ARENA_H_
#define ARENA_H_

// maybe infer this from os specific compiler directives?

#define MALLOC_BACKEND 0
#define VIRTUAL_ALLOC_BACKEND 0

#ifndef ALLOC_BACKEND
#define ALLOC_BACKEND MALLOC_BACKEND
#endif

#include <stdio.h>
#include <assert.h>

#if ALLOC_BACKEND == MALLOC_BACKEND
	#include <stdlib.h>
#endif

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
