#include "arena.h"

Arena *arena_create(size_t capacity)
{
    Arena *arena = (Arena *)calloc(1, sizeof(Arena));
    arena->size = 0;
    arena->capacity = capacity;
    arena->mem = NULL;

    return arena;
}

void arena_release(Arena *arena)
{
    arena->mem = NULL;
    arena->size = 0;
    free(arena);
}
