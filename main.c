#define ALLOC_BACKEND VIRTUAL_ALLOC_BACKEND

#include "arena.h"

int main(void)
{
	ArenaAllocator *a = arena_init(40);
	printf("%zd\n", 10 * sizeof(int));

	int *array = (int *)arena_push(a, 10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		array[i] = (i + 1) * (i + 2);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}

	arena_reset(a);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}