#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} typedef Node;

Node *createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("\nFailed to Allocate Memory!\n");
        exit(-1);
    }
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

int countNodes(Node *head)
{
    int numberOfNodes = 0;
    while (head)
    {
        numberOfNodes++;
        head = head->next;
    }
    return numberOfNodes;
}

Node *insertAtStart(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("\nFailed to Allocate Memory!\n\n");
        exit(-1);
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertAtNth(Node *head, int position, int data)
{
    Node *temp, *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("\nFailed to Allocate Memory!\n\n");
        exit(-1);
    }

    newNode->data = data;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *temp, *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("\nFailed to Allocate Memory!\n\n");
        exit(-1);
    }

    newNode->data = data;
    newNode->next = NULL;
    temp = head;
    while (temp && temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(Node *head)
{
    if (!head)
    {
        printf("\nLinked List Empty!\n\n");
        exit(-1);
    }
    printf("Your Linked List: \n");

    while (head)
    {
        printf("|%d|->", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    Node *head = NULL, *temp = NULL;
    int size;
    printf("Enter Size of Singly Linked List: ");
    scanf("%d", &size);
    while (size--)
    {
        if (!head)
        {
            head = createNode();
            head->next = NULL;
        }
        else
        {
            temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = createNode();
        }
    }
    printf("\n");
    printList(head);
    head = insertAtStart(head, 0);
    printList(head);
    head = insertAtEnd(head, 6);
    printList(head);
    head = insertAtNth(head, 8, 69);
    printList(head);
    return 0;
}
