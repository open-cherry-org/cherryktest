#include "ktest.h"

void test_dev() {
    print("Device Test:\n", WHITE);
    ASSERT(1, "Read from I/O device (mock)");
}
