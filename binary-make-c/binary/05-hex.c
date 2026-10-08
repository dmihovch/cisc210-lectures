#include <stdio.h>
#include <unistd.h>
#include "piemulator.h"

/* compile: cc 05-hex.c piemulator.c -pthread -o 05-hex */
/* library: https://github.com/dmihovch/raspberry-pie */

#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define YELLOW  0xFFE0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define WHITE   0xFFFF
#define BLACK   0x0000

void print_rgb565(uint16_t color) {
    for (int bit = 15; bit >= 11; bit--) {
        printf("%u", (color >> bit) & 1);
    }
    printf(" ");
    for (int bit = 10; bit >= 5; bit--) {
        printf("%u", (color >> bit) & 1);
    }
    printf(" ");
    for (int bit = 4; bit >= 0; bit--) {
        printf("%u", (color >> bit) & 1);
    }
}

int main(void) {
    uint16_t colors[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE};
    int color_count = sizeof(colors) / sizeof(colors[0]);

    printf("a color is 16 bits: 5 red, 6 green, 5 blue\n");
    printf("getColor(255, 0, 0) = 0x%04X\n", getColor(255, 0, 0));
    for (int i = 0; i < color_count; i++) {
        printf("0x%04X = %5u = ", colors[i], colors[i]);
        print_rgb565(colors[i]);
        printf("\n");
    }
    printf("press enter to light up the display\n");
    getchar();

    pi_framebuffer_t *fb = getFrameBuffer();
    if (fb == NULL) {
        return 1;
    }

    for (int i = 0; i < color_count; i++) {
        clearFrameBuffer(fb, colors[i]);
        usleep(500000);
    }

    uint16_t rainbow[] = {RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, WHITE, RED};
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            fb->bitmap->pixel[x][y] = rainbow[x];
        }
    }
    usleep(2000000);

    clearFrameBuffer(fb, BLACK);
    freeFrameBuffer(fb);
    return 0;
}