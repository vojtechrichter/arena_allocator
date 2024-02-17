#include "arena.h"

int main(void)
{
	Arena arena = arena_init(10 * sizeof(int));

	int *arr = (int *)arena_alloc(&arena, 5 * sizeof(int));

	for (int i = 0; i < 5; i++) {
		arr[i] = (i * 2) + (i * i / 5);
	}
	
	for (int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}

	arena_free(&arena);

	return 0;
}
