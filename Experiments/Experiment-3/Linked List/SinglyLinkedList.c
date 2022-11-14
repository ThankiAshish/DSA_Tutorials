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

    return newNode;
}

int main(void)
{
    Node *head = NULL, *temp = NULL;
    int size;
    printf("Enter Size of Singly Linked List: ");
    scanf("%d", &size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = createNode();
            head->next = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = createNode();
        }
    }
    printf("\n");
    printList(head);
    return 0;
}
