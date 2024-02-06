#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file[4];
    char f[4][100] = {
        "/Users/nischalneupane/Desktop/C/Assessment/DatasetsTask1/datasetLR1.txt",
        "/Users/nischalneupane/Desktop/C/Assessment/DatasetsTask1/datasetLR2.txt",
        "/Users/nischalneupane/Desktop/C/Assessment/DatasetsTask1/datasetLR3.txt",
        "/Users/nischalneupane/Desktop/C/Assessment/DatasetsTask1/datasetLR4.txt"};

    int x[700], y[700], n = 0;
    float Xsum = 0, Ysum = 0, sumofXY = 0, sumofsquaredX = 0;

    for (int i = 0; i < 4; i++)
    {
        file[i] = fopen(f[i], "r");

        while (fscanf(file[i], "%d,%d", &x[n], &y[n]) == 2)
        {
            Xsum += x[n];
            Ysum += y[n];
            sumofXY += x[n] * y[n];
            sumofsquaredX += x[n] * x[n];
            n++;
        }
        fclose(file[i]);
    }

    float a, b;

    a = ((Ysum * sumofsquaredX) - (Xsum * sumofXY)) / ((n * sumofsquaredX) - (Xsum * Xsum));
    b = ((n * sumofXY) - (Xsum * Ysum)) / ((n * sumofsquaredX) - (Xsum * Xsum));

    printf("eqn: y = %.4fx + %.4f\n", b, a);

    int X;
    printf("Write value for x: ");
    scanf("%d", &X);

    while (scanf("%d", &X) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n')
            ;
    }

    float Y;
    Y = b * X + a;
    printf("For x = %d, y = %.4f\n", X, Y);

    return 0;
}
