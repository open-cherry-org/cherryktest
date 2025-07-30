#include "ktest.h"

void test_mem();
void test_fs();
void test_sys();
void test_shell();
void test_dev();

void _start() {
    print("=== Cherry KTest Kernel ===\n", WHITE);
    test_mem();
    test_fs();
    test_sys();
    test_shell();
    test_dev();
    print("=== DONE ===\n", WHITE);
    for (;;); // Halt
}
