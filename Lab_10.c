#include <stdio.h>
#include <limits.h>

struct SimpleArray
{
    int arr[20];
};

void assign(int p, int f, int cf, int fr[])
{
    fr[cf] = p;
    printf("%d assigned to frame %d", p, cf);
    printf("\nFrames: ");
    for (int i = 0; i < f; i++)
    {
        if (fr[i] >= 0)
            printf("%d ", fr[i]);
    }
    printf("\n");
}

void FIFO(int rfl, struct SimpleArray rf, int f)
{
    int fr[10], pgf = 0, adder = 0;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = 0; j < i - adder + 1; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                adder++;
                break;
            }
        }
        if (j == i - adder + 1)
        {
            pgf++;
            assign(rf.arr[i], i - adder + 1, i - adder, fr);
        }
    }
    int curframe = 0;
    for (int i = f; i < rfl; i++)
    {
        int j = 0;
        for (j = 0; j < f; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                break;
            }
        }
        if (j == f)
        {
            pgf++;
            assign(rf.arr[i], f, curframe, fr);
            curframe++;
            curframe %= f;
        }
    }
    printf("Page Faults: %d\n\n", pgf);
}

void optimal(int rfl, struct SimpleArray rf, int f)
{
    int fr[10], pgf = 0, adder = 0;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = 0; j < i - adder + 1; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                adder++;
                break;
            }
        }
        if (j == i - adder + 1)
        {
            pgf++;
            assign(rf.arr[i], i - adder + 1, i - adder, fr);
        }
    }
    for (int i = f; i < rfl; i++)
    {
        int j = 0;
        for (j = 0; j < f; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                break;
            }
        }
        if (j == f)
        {
            pgf++;
            int max = 0, ind = 0;
            for (int l = 0; l < f; l++)
            {
                int eqd = 0;
                for (int k = i; k < rfl; k++)
                {
                    if (rf.arr[k] == fr[l])
                    {
                        eqd = 1;
                        if (k > max)
                        {
                            max = k;
                            ind = l;
                            break;
                        }
                    }
                }
                if (eqd == 0)
                {
                    ind = l;
                    break;
                }
            }
            assign(rf.arr[i], f, ind, fr);
        }
    }
    printf("Page Faults: %d\n\n", pgf);
}

void lru(int rfl, struct SimpleArray rf, int f)
{
    int fr[10], pgf = 0, adder = 0;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = 0; j < i - adder + 1; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                adder++;
                break;
            }
        }
        if (j == i - adder + 1)
        {
            pgf++;
            assign(rf.arr[i], i - adder + 1, i - adder, fr);
        }
    }
    for (int i = f; i < rfl; i++)
    {
        int j = 0;
        for (j = 0; j < f; j++)
        {
            if (fr[j] == rf.arr[i])
            {
                printf("Skipping %d\n", rf.arr[i]);
                break;
            }
        }
        if (j == f)
        {
            pgf++;
            int max = 0, ind = 0;
            for (int l = 0; l < f; l++)
            {
                int eqd = 0;
                for (int k = i; k >= 0; k--)
                {
                    if (rf.arr[k] == fr[l])
                    {
                        eqd = 1;
                        if (i - k > max)
                        {
                            max = i - k;
                            ind = l;
                            break;
                        }
                    }
                }
                if (eqd == 0)
                {
                    ind = l;
                    break;
                }
            }
            assign(rf.arr[i], f, ind, fr);
        }
    }
    printf("Page Faults: %d\n\n", pgf);
}

int main()
{
    int rfl, f;
    struct SimpleArray rf;
    printf("\nPAGE REPLACEMENT ALGORITHMS\n\n");
    printf("Input the Length of Reference String\n");
    scanf("%i", &rfl);
    printf("Enter the Reference String...\n");
    for (int i = 0; i < rfl; i++)
        scanf("%d", &rf.arr[i]);

    printf("Enter the number of frames\n");
    scanf("%d", &f);

    printf("\nFIFO:\n");
    FIFO(rfl, rf, f);

    printf("\nOptimal Page Replacement:\n");
    optimal(rfl, rf, f);

    printf("\nLeast Recently Used:\n");
    lru(rfl, rf, f);
    return 0;
}