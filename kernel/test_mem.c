#include "ktest.h"

void test_mem() {
    print("Memory Test:\n", WHITE);
    char block[128];
    block[0] = 'X';
    ASSERT(block[0] == 'X', "Allocate stack memory");
}
