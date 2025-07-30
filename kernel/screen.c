#pragma once

#define VGA_ADDRESS 0xB8000
#define WHITE 0x0F
#define GREEN 0x2F
#define RED   0x4F

void print(const char *msg, int color);

#define ASSERT(cond, msg) do { \
    if (cond) print("[PASS] " msg "\n", GREEN); \
    else      print("[FAIL] " msg "\n", RED);   \
} while(0)
