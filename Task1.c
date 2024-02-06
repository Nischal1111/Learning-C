#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f = fopen("/Users/nischalneupane/Desktop/C/Assessment/DatasetsTask1/datasetLR1.txt", "r");

    if (f == NULL)
    {
        printf("Error");
    }

    int x[130], y[130], n = 0;
    float Xsum = 0, Ysum = 0, sumofXY = 0, sumofsquaredX = 0;

    while (fscanf(f, "%d,%d", &x[n], &y[n]) == 2)
    {
        Xsum += x[n];
        Ysum += y[n];
        sumofXY += x[n] * y[n];
        sumofsquaredX += x[n] * x[n];
        n++;
    }

    float a, b;

    a = ((Ysum * sumofsquaredX) - (Xsum * sumofXY)) / ((n * sumofsquaredX) - (Xsum * Xsum));
    b = ((n * sumofXY) - (Xsum * Ysum)) / ((n * sumofsquaredX) - (Xsum * Xsum));

    printf("eqn: y = %.4fx + %.4f\n", b, a);

    int X;
    printf("Write value for x:  ");
    scanf("%d", &X);

    float Y;
    Y = a + b * X;
    printf("For x = %d, y = %.4f\n", X, Y);

    fclose(f);
    return 0;
}