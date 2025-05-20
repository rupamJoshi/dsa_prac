#include <stdio.h>
#include <stdlib.h>

typedef struct __stack_node
{
    int num;
    struct __stack_node *next;
} StackNode;

typedef struct __stack
{
    StackNode *top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, int numberTobePushed)
{
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    node->num = numberTobePushed;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack)
{
    int num;
    if (stack->top == NULL)
    {
        return -1;
    }
    num = stack->top->num;
    stack->top = stack->top->next;
    return num;
}

int isStackEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

int merge(int *x, int lb1, int ub1, int lb2, int ub2)
{
    int result[10];
    int ub3;
    int g;
    ub3 = lb1;
    int lb = lb1;
    int ub = ub2;
    printf("%d %d %d %d\n", lb1, ub1, lb2, ub2);
    while (lb1 <= ub1 && lb2 <= ub2)
    {
        if (x[lb1] < x[lb2])
        {
            result[ub3] = x[lb1];
            lb1++;
        }
        else
        {
            result[ub3] = x[lb2];
            lb2++;
        }
        ub3++;
    }
    while (lb1 <= ub1)
    {
        result[ub3] = x[lb1];
        lb1++;
        ub3++;
    }
    while (lb2 <= ub2)
    {
        result[ub3] = x[lb2];
        lb2++;
        ub3++;
    }

    int i = 0;
    ub3 = lb;
    while (ub3 <= ub2)
    {
        x[ub3] = result[ub3];
        ub3++;
    }
}

int mergeSort(int *x, int size)
{

    int lb = 0;
    int ub = size - 1;
    int a, b, mid;
    Stack *stack1_lb, *stack1_ub, *stack2_lb, *stack2_ub;
    stack1_lb = (Stack *)malloc(sizeof(Stack));
    stack1_ub = (Stack *)malloc(sizeof(Stack));
    stack2_lb = (Stack *)malloc(sizeof(Stack));
    stack2_ub = (Stack *)malloc(sizeof(Stack));

    push(stack1_lb, lb);
    push(stack1_ub, ub);

    while (!isStackEmpty(stack1_lb))
    {
        a = pop(stack1_lb);
        b = pop(stack1_ub);
        push(stack2_lb, a);
        push(stack2_ub, b);
        mid = (a + b) / 2;
        if (a < mid)
        {
            push(stack1_lb, a);
            push(stack1_ub, mid);
        }
        if (mid + 1 < b)
        {
            push(stack1_lb, mid + 1);
            push(stack1_ub, b);
        }
    }
    int i = 0;
    while (!isStackEmpty(stack2_lb))
    {
        int lb1 = pop(stack2_lb);
        int ub2 = pop(stack2_ub);
        int ub1 = (lb1 + ub2) / 2;
        int lb2 = ub1 + 1;
        merge(x, lb1, ub1, lb2, ub2);
        i++;
    }
    return 0;
}

int main()
{

    int x[10];
    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("Enter a number 1x .. \n");
        scanf("%d", &x[i]);
    }
    mergeSort(x, 10);
    for (i = 0; i < 10; ++i)
    {
        printf("%d \n", x[i]);
    }
    return 0;
}