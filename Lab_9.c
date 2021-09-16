#include <stdio.h>
#include <limits.h>

struct SimpleArray
{
    int arr[10];
};

void firstFit(int hn, struct SimpleArray h, int pn, struct SimpleArray p)
{
    for (int i = 0; i < pn; i++)
    {
        int j = 0;
        for (j = 0; j < hn; j++)
        {
            if (h.arr[j] >= p.arr[i])
            {
                printf("Process P%d: Size: %d, Goes to hole H%d.\n", i, p.arr[i], j);
                h.arr[j] -= p.arr[i];
                break;
            }
        }
        if (j == hn)
            printf("Process P%d: Size: %d, Could not assign to a hole!\n", i, p.arr[i]);
    }
}

void bestFit(int hn, struct SimpleArray h, int pn, struct SimpleArray p)
{
    for (int i = 0; i < pn; i++)
    {
        int minDif = -1, index = 0;
        for (int j = 0; j < hn; j++)
        {
            if ((minDif == -1 || h.arr[j] - p.arr[i] < minDif) && h.arr[j] >= p.arr[i])
            {
                minDif = h.arr[j] - p.arr[i];
                index = j;
            }
        }
        if (minDif != -1)
        {
            printf("Process P%d: Size: %d, Goes to hole H%d.\n", i, p.arr[i], index);
            h.arr[index] -= p.arr[i];
        }
        else
            printf("Process P%d: Size: %d, Could not assign to a hole!\n", i, p.arr[i]);
    }
}

void worstFit(int hn, struct SimpleArray h, int pn, struct SimpleArray p)
{
    for (int i = 0; i < pn; i++)
    {
        int maxDif = -1, index = 0;
        for (int j = 0; j < hn; j++)
        {
            if ((maxDif == -1 || h.arr[j] - p.arr[i] > maxDif) && h.arr[j] >= p.arr[i])
            {
                maxDif = h.arr[j] - p.arr[i];
                index = j;
            }
        }
        if (maxDif != -1)
        {
            printf("Process P%d: Size: %d, Goes to hole H%d.\n", i, p.arr[i], index);
            h.arr[index] -= p.arr[i];
        }
        else
            printf("Process P%d: Size: %d, Could not assign to a hole!\n", i, p.arr[i]);
    }
}

int main()
{
    int hn, pn;
    struct SimpleArray h, p;
    printf("\nMEMORY ALLOCATION METHODS FOR FIXED PARTITION\n\n");
    printf("Enter the number of holes\n");
    scanf("%i", &hn);
    printf("Enter the sizes of holes...\n");
    for (int i = 0; i < hn; i++)
        scanf("%d", &h.arr[i]);

    printf("Enter the number of processes\n");
    scanf("%d", &pn);
    printf("Enter the sizes of processes...\n");
    for (int i = 0; i < pn; i++)
        scanf("%d", &p.arr[i]);

    printf("\nFirst Fit:\n");
    firstFit(hn, h, pn, p);

    printf("\nBest Fit:\n");
    bestFit(hn, h, pn, p);

    printf("\nWorst Fit:\n");
    worstFit(hn, h, pn, p);
    return 0;
}