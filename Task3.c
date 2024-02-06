#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ThreadData
{
    int *numbers;
    int start;
    int end;
    int *primes;
    int *primesCount;
};

FILE *file1 = fopen("/Users/nischalneupane/Desktop/C/DatasetsTask3/PrimeData1.txt", "r");
FILE *file2 = fopen("/Users/nischalneupane/Desktop/C/DatasetsTask3/PrimeData2.txt", "r");
FILE *file3 = fopen("/Users/nischalneupane/Desktop/C/DatasetsTask3/PrimeData3.txt", "r");
