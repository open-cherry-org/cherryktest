#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_ADDRESS 0xB8000
static int row = 0;

void print(const char *msg, int color) {
    volatile char *vga = (volatile char*) VGA_ADDRESS;
    while (*msg) {
        if (*msg == '\n') {
            row++;
            msg++;
            continue;
        }
        int offset = (row * VGA_WIDTH + 0);
        for (int i = 0; msg[i] && msg[i] != '\n'; i++) {
            vga[offset * 2] = msg[i];
            vga[offset * 2 + 1] = color;
            offset++;
        }
        break;
    }
    row++;
}
