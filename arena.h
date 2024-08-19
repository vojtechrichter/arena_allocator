#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef uint8_t Ubyte;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef int8_t SByte;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

#define MALLOC_BACKEND 0
#define VIRTUAL_ALLOC_BACKEND 1

#ifndef ARENA_ASSERT
	#define ARENA_ASSERT(c) assert(c)
#endif

#ifndef ALLOC_BACKEND
	#define ALLOC_BACKEND MALLOC_BACKEND
#endif // ALLOC_BACKEND

typedef struct ArenaAllocator ArenaAllocator;
struct ArenaAllocator {
	size_t pos;
	size_t cap;
	uintptr_t *mem;
};

#if ALLOC_BACKEND == MALLOC_BACKEND

ArenaAllocator *arena_init(size_t capacity)
{
	ArenaAllocator *aa = (ArenaAllocator *)malloc(sizeof(ArenaAllocator));
	aa->pos = 0;
	aa->cap = capacity;
	aa->mem = (uintptr_t *)malloc(capacity);

	return aa;
}

#endif // ALLOC_BACKEND == MALLOC_BACKEND

void *arena_push(ArenaAllocator *arena, size_t size)
{
	ARENA_ASSERT(arena->pos + size < arena->cap);

	arena->pos += size;

	return (arena->mem + arena->pos);
}

void arena_reset(ArenaAllocator *arena)
{
	arena->pos = 0;
}

void arena_pop(ArenaAllocator *arena, size_t amount)
{
	arena->pos -= amount;
}

#endif // ARENA_H