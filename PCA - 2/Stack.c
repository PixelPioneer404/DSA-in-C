#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX], top = -1;

void displayStack()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d, ", stack[i]);
    }
}

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack[top] = item;
    displayStack();
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    printf("The poped item is: %d\n", stack[top]);
    top = top - 1;
    displayStack();
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    printf("%d\n", stack[top]);
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------------------------");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.display stack\n5.Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int val;
            printf("Enter a value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            displayStack();
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid Choice");
        }
        }
    }
}