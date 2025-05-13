#include <stdio.h>
void heapSort(int *x, int size)
{

    int i;
    int y, g, ci, ri, lci, rci, swi;
    y = 1;
    while (y < size)
    {
        ci = y;
        while (ci > 0)
        {
            ri = (ci - 1) / 2;
            if (x[ci] > x[ri])
            {
                g = x[ci];
                x[ci] = x[ri];
                x[ri] = g;
                ci = ri;
            }
            else
            {
                break;
            }
        }

        y++;
    }

    y = size - 1;
    while (y > 0)
    {
        g = x[0];
        x[0] = x[y];
        x[y] = g;
        y--;
        ri = 0;
        while (ri < y)
        {
            lci = (ri * 2) + 1;

            if (lci > y)
                break;
            rci = (lci) + 1;
            if (rci > y)
            {
                swi = lci;
            }
            else if (x[lci] > x[rci])
            {
                swi = lci;
            }
            else
            {
                swi = rci;
            }
            if (x[swi] > x[ri])
            {
                g = x[swi];
                x[swi] = x[ri];
                x[ri] = g;
                printf("%d %d\n", x[swi], x[ri]);
                ri = swi;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{

    int x[10];
    int i;

    for (i = 0; i < 10; ++i)
    {
        printf("Enter a number :");
        scanf("%d", &x[i]);
    }
    heapSort(x, 10);

    printf(" after sorting the array \n");

    for (i = 0; i < 10; ++i)
    {
        printf("%d \n", x[i]);
    }
}