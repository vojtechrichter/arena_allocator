#include "arena.h"

Arena arena_init(size_t capacity)
{
	Arena arena = {0};
	arena.capacity = capacity;
	arena.size = 0;
	arena.mem = calloc(1, capacity);

	return arena;
}

char *arena_alloc(Arena *arena, size_t alloc_size)
{
	assert((arena->size + alloc_size) < arena->capacity);

	arena->size += alloc_size;

	char *alloc = arena->mem + alloc_size;

	return alloc;
}

void arena_reset(Arena *arena)
{
	arena->size = 0;
	arena->mem = (void *)0;
}

void arena_free(Arena *arena)
{
	free(arena->mem);
	arena = (void *)0;
}
