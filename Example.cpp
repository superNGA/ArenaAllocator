#include "ArenaAllocator.h"


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int main(void)
{
    ArenaAllocator_t arena;

    for(int i = 0; i < 100; i++)
    {
        void* pMem = arena.Allocate(100);
        printf("Allocation %d : %p\n", i, pMem);
    }

    // Before free.
    printf("Total size     : %llu\n", arena.TotalSize());
    printf("Total Capacity : %llu\n", arena.TotalCapacity());
    printf("Total Arenas   : %zu\n",  arena.ArenaCount());

    arena.ResetAllArena();

    // After free.
    printf("Total size     : %llu\n", arena.TotalSize());
    printf("Total Capacity : %llu\n", arena.TotalCapacity());
    printf("Total Arenas   : %zu\n",  arena.ArenaCount());

    arena.FreeAll();

    // After free.
    printf("Total size     : %llu\n", arena.TotalSize());
    printf("Total Capacity : %llu\n", arena.TotalCapacity());
    printf("Total Arenas   : %zu\n",  arena.ArenaCount());

    return 0;
}
