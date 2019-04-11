#include <stdio.h>
#include "Image.h"
#include "Color.h"

void xadrez(Image img)
{
    Color preto = {0, 0, 0};
    Color branco = {255, 255, 255};

    initImage(img, preto);


    for(int j = 0; j < img.h; j += 200)
        for(int i = 0; i < img.w; i += 200)
            draw_rectangle(img, branco, i, j, i + 100, j + 100);

    for(int j = 100; j < img.h; j += 200)
        for(int i = 100; i < img.w; i += 200)
            draw_rectangle(img, branco, i, j, i + 100, j + 100);

    savePng("xadrez.png", img);
}

void imagemBonitinha(Image img)
{
    Color A = {255, 0, 0}, B = {0, 255, 0}, C = {0, 0, 255}, D = {255, 0, 255};

    for (int j = 0; j < img.h; j++)
    {
        float v = (float) j/(img.h-1);

        for (int i = 0; i < img.w; i++)
        {
            float u = (float) i/(img.w-1);
            Ponto p = {i, j};
            draw_pixel(img, interpolacaoBilinear(u, v, A, B, C, D), p);
        }
    }

    savePng("imagemBonitinha.png", img);
}

int circle(int x, int y)
{
    int r = 200;

    return (x-200)*(x-200) + (y-200)*(y-200) - r*r;
}

int line(int x, int y)
{
    int a = 2, b = 3;

    return a*x + b - y;
}

int main()
{
    Image img = newImage(800, 600);

    Color branco = {255, 255, 255}, vermelho = {255, 0, 0};

    initImage(img, branco);

    Ponto p[] = {
            {400, 200},
            {200, 100},
            {100, 300},
            {300, 400},
            {600, 500},
            {700, 100}
    };

    draw_triangle_fan(img, vermelho, p, 6);

    savePng("triangulo.png", img);

    return 0;
}
