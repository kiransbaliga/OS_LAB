#include <stdio.h>
#include <stdlib.h>
int n, in = 0, out = 0;
int size;
int a[20];
void producer()
{
    if ((in + 1) % size == out)
    {
        printf("Buffer is full\n");
        return;
    }
    printf("How many item want to produce?\n");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        if ((in + i) % size == out)
        {
            printf("Cant produce %i items\n", n);
            return;
        }
    }
    int y = out;
    printf("Enter the values\n");
    for (int i = 1; i <= n; i++)
    {
        in = (in + 1) % size;
        scanf("%i", &a[in]);
    }
    printf("Successfully produced\n");
    printf("Contents of buffer\n");
    while (y != in)
    {
        y = (y + 1) % size;
        printf("%i ", a[y]);
    }
}
void consumer()
{
    if (in == out)
    {
        printf("Buffer is empty\n");
        return;
    }
    printf("Successfully consumed\n");
    printf("Consumed item\n");
    out = (out + 1) % size;
    printf("%i ", a[out]);
    int y = out;
    printf("\nContents of buffer\n");
    if (y != in)
    {
        while (y != in)
        {
            y = (y + 1) % size;
            printf("%i ", a[y]);
        }
    }
    else
    {
        printf("Buffer is empty\n");
    }
    //printf("%i %i",in ,out);
}
int main()
{
    int n, i;
    size = 10;
    for (int j = 0; j <= size; j++)
    {
        a[j] = 0;
    }
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
    for (i = 1; i > 0; i++)
    {        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            exit(0);
            break;
        }
    }
}