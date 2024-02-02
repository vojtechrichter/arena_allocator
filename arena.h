#ifndef ARENA_H_
#define ARENA_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#define LIBC_MALLOC_BACKEND 0x0
#define WIN32_VIRTUAL_ALLOC_BACKEND 0x1

#ifndef ARENA_BACKEND
    #define ARENA_BACKEND LIBC_MALLOC_BACKEND
#endif // ARENA_BACKEND

#define ARENA_ASSERT assert

#define arena_true 1
#define arena_false 0

#define DEFAULT_ARENA_CAPACITY 1024

typedef struct {
    size_t size;
    size_t capacity;
    char *mem;
} Arena;

#if ARENA_BACKEND == LIBC_MALLOC_BACKEND

Arena *arena_create(size_t capacity);
void arena_release(Arena *arena);

#endif

#endif // ARENA_H_ 
