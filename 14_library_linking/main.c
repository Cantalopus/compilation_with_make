#include <math.h>
#include <stdio.h>

int main(void)
{
    double width, height;

    printf("Enter width and height: ");
    if (scanf("%lf %lf", &width, &height) != 2)
        return 1;

    printf("Diagonal: %.3f\n", hypot(width, height));
    return 12;
}