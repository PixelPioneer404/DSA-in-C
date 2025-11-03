#include <stdio.h>
#include <stdlib.h>

struct DNode
{
    struct DNode *prev;
    int data;
    struct DNode *next;
};

struct DNode *head;

struct DNode *createNode(int val)
{
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->prev = NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void displayNode()
{
    struct DNode *temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void insertAtFirst(int val)
{
    struct DNode *newNode = createNode(val);
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    displayNode();
}

void insertAtLast(int val)
{
    struct DNode *newNode = createNode(val);
    struct DNode *temp = head;
    if (head == NULL)
    {
        head = newNode;
        displayNode();
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    displayNode();
}

void deleteFromFirst()
{
    if (head == NULL)
    {
        printf("There is no node ot delete");
        return;
    }
    struct DNode *temp = head;
    if (head->next != NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL;
    }
    printf("Deleted Node is: %d\n", temp->data);
    displayNode();
    free(temp);
}

void deleteFromLast()
{
    if (head == NULL)
    {
        printf("There is no node ot delete");
        return;
    }
    struct DNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    printf("Deleted Node is: %d\n", temp->data);
    displayNode();
    free(temp);
}

int main()
{
    int ch;
    head = createNode(10);
    while (1)
    {
        printf("\n------------------------------------------------");
        printf("\n1.Insert at First\n2.Insert at Last\n3.Delete from First\n4.Delete from Last\n5.Display the list\n6.Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int val;
            printf("Enter a value to insert: ");
            scanf("%d", &val);
            insertAtFirst(val);
            break;
        }
        case 2:
        {
            int val;
            printf("Enter a value to insert: ");
            scanf("%d", &val);
            insertAtLast(val);
            break;
        }
        case 3:
        {
            deleteFromFirst();
            break;
        }
        case 4:
        {
            deleteFromLast();
            break;
        }
        case 5:
        {
            displayNode();
            break;
        }
        case 6:
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