#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;

void displayQueue()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d, ", queue[i]);
    }
}

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    displayQueue();
}

void dqueue()
{
    if (front == -1) {
        printf("Queue underflow");
        return;
    }
    printf("Deleted item is: %d\n", queue[front]);
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
    }
    displayQueue();
}

void Peak()
{
    if (front == -1) {
        printf("Queue is empty");
        return;
    }
    printf("Top most item is: %d\n", queue[rear]);
    displayQueue();
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------------------------");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peak\n4.Display Queue\n5.Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int val;
            printf("Enter a value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        }
        case 2:
        {
            dqueue();
            break;
        }
        case 3:
        {
            Peak();
            break;
        }
        case 4:
        {
            displayQueue();
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