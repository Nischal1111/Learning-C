#include <stdio.h>
#include <pthread.h>

typedef struct
{
    int start;
    int end;
    double result;
} td;

void *mini_sum(void *p)
{
    td *data = (td *)p;
    double sum = 0.0;

    for (int i = data->start; i < data->end; i++)
    {
        if (i % 2 == 0)
        {
            sum += 1 / (2.0 * i + 1);
        }
        else
        {
            sum -= 1 / (2.0 * i + 1);
        }
    }

    data->result = sum;

    pthread_exit(NULL);
}

int main()
{

    int iterations, num;

    printf("Number of iterations: ");
    scanf("%d", &iterations);

    printf("Number of threads: ");
    scanf("%d", &num);

    pthread_t threads[num];
    td data[num];

    double total_sum = 0.0;

    int range = iterations / num;

    for (int i = 0; i < num; i++)
    {
        data[i].start = i * range;
        data[i].end = (i + 1) * range;
        pthread_create(&threads[i], NULL, mini_sum, &data[i]);
    }

    for (int i = 0; i < num; i++)
    {
        pthread_join(threads[i], NULL);
        total_sum += data[i].result;
    }

    double result = total_sum * 4.0;

    printf("Pi: %.10lf\n", result);

    return 0;
}
