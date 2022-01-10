#include "../include/common.h"
#include "../include/fileOperator.h"
#include "../include/tgaImage.h"

#define WIDTH 800
#define HEIGHT 800
int main(int argc, char *argv[]) {
    TGAImage framebuffer(WIDTH, HEIGHT, TGAImage::RGB);

    for (int i = 0; i < WIDTH;i++)
        for (int j = 0; j < HEIGHT;j++)
            framebuffer.set(i, j, TGAColor(i * 255 / WIDTH, j * 255 / HEIGHT, 
            (i + j) * 255 / (WIDTH + HEIGHT)));

    framebuffer.write_tga_file("main.tga");
    return 0;
}