#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <locale.h>
#include <stdio.h>
#include <math.h>

int homework(int i, int j, double d1, double d2, double alpha, int cx, int cy);

int main()
{
    setlocale(LC_ALL, "RUS");

    char symbol;
    double d1, d2, alpha;
    int contin;

    do
    {
        puts("Введите символ, из которого будет строиться фигура");
        scanf(" %c", &symbol);

        puts("Введите длину первой диагонали d1");
        scanf("%lf", &d1);

        puts("Введите длину второй диагонали d2");
        scanf("%lf", &d2);

        puts("Введите угол между диагоналями alpha (в градусах)");
        scanf("%lf", &alpha);

        if (d1 <= 0 || d2 <= 0 || alpha <= 0 || alpha >= 180)
        {
            printf("Ошибка! Диагонали должны быть больше 0, угол 0 < α < 180\n");
        }
        else
        {
            printf("Четырёхугольник (символ '%c', d1=%.1f, d2=%.1f, α=%.1f°)\n\n",
                symbol, d1, d2, alpha);

            
            int cx = 40;
            int cy = 20;

            for (int i = 0; i < 45; i++)
            {
                for (int j = 0; j < 80; j++)
                {
                    if (homework(i, j, d1, d2, alpha, cx, cy))
                    {
                        printf("%c", symbol);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

        puts("\nПродолжить? (Да - введите любое число, Нет - введите 0)");
        scanf("%d", &contin);
    } while (contin != 0);

    printf("Программа завершена\n");
    return 0;
}

int homework(int i, int j, double d1, double d2, double alpha, int cx, int cy)
{
    int res = 0;

    double alphaRad = alpha * M_PI / 180.0;

    double aspect = 0.5;

    int x1 = cx - (int)(d1 / 2);
    int y1 = cy;

    int x2 = cx + (int)(d2 / 2 * cos(alphaRad));
    int y2 = cy - (int)(d2 / 2 * sin(alphaRad) * aspect);

    int x3 = cx + (int)(d1 / 2);
    int y3 = cy;

    int x4 = cx - (int)(d2 / 2 * cos(alphaRad));
    int y4 = cy + (int)(d2 / 2 * sin(alphaRad) * aspect);

    int dx1 = x2 - x1, dy1 = y2 - y1;
    int dx2 = x3 - x2, dy2 = y3 - y2;
    int dx3 = x4 - x3, dy3 = y4 - y3;
    int dx4 = x1 - x4, dy4 = y1 - y4;

    int dx1p = j - x1, dy1p = i - y1;
    int dx2p = j - x2, dy2p = i - y2;
    int dx3p = j - x3, dy3p = i - y3;
    int dx4p = j - x4, dy4p = i - y4;

    int cp1 = dx1 * dy1p - dy1 * dx1p;
    int cp2 = dx2 * dy2p - dy2 * dx2p;
    int cp3 = dx3 * dy3p - dy3 * dx3p;
    int cp4 = dx4 * dy4p - dy4 * dx4p;

    int allPositive = (cp1 >= 0 && cp2 >= 0 && cp3 >= 0 && cp4 >= 0);
    int allNegative = (cp1 <= 0 && cp2 <= 0 && cp3 <= 0 && cp4 <= 0);

    if (allPositive || allNegative)
        res = 1;

    return res;
}