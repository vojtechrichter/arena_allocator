#include "arena.h"

int main(void)
{
    Arena *arena = arena_create(DEFAULT_ARENA_CAPACITY);
    arena_release(arena);

    return 0;
}
