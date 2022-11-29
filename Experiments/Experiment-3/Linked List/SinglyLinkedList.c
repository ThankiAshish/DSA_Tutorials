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
    printf("%d Inserted!\n", data);
    return head;
}

Node *insertAtNth(Node *head, int position, int data)
{
    if (position < 1 || position > countNodes(head) + 1)
    {
        printf("\nInvalid Position!\n");
        return head;
    }

    Node *temp, *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("\nFailed to Allocate Memory!\n\n");
        exit(-1);
    }

    newNode->data = data;
    if (position == 1)
    {
        return insertAtStart(head, data);
    }

    temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d Inserted!\n", data);
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
    printf("\n%d Inserted!", data);
    return head;
}

Node *deleteStart(Node *head)
{
    Node *currentNode = head;
    head = currentNode->next;
    free(currentNode);
    currentNode = NULL;
    printf("Node Deleted!\n");
    return head;
}

Node *deleteNth(Node *head, int position)
{
    Node *currentNode = head;
    Node *previousNode = head;

    if (position < 1 || position > countNodes(head))
    {
        printf("\nInvalid Position!\n\n");
        return head;
    }

    if (!head)
    {
        printf("\nLinked List Empty!\n\n");
        exit(-1);
    }

    if (position == 1)
    {
        return deleteStart(head);
    }

    while (position != 1)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
        position--;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    currentNode = NULL;
    printf("Node Deleted!\n");
    return head;
}

Node *deleteEnd(Node *head)
{
    Node *currentNode = head;
    Node *previousNode = head;

    while (previousNode->next->next)
        previousNode = previousNode->next;

    while (currentNode)
        currentNode = currentNode->next;

    previousNode->next = NULL;
    free(currentNode);
    currentNode = NULL;
    printf("Node Deleted!\n");
    return head;
}

int searchElement(Node *head, int element)
{
    int position = 0;
    while (head)
    {
        position++;
        if (head->data == element)
            return position;
        head = head->next;
    }
    return -1;
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

void menu()
{
    printf("\nSelect a Operation From Below: ");
    printf("\n\t1. Insert At Start");
    printf("\n\t2. Insert At End");
    printf("\n\t3. Insert At Nth");
    printf("\n\t4. Delete From Start");
    printf("\n\t5. Delete From End");
    printf("\n\t6. Delete From Nth");
    printf("\n\t7. Search Element");
    printf("\n\t8. Display");
    printf("\n\t9. Exit");
    printf("\nEnter Your Choice: ");
    return;
}

int main(void)
{
    Node *head = NULL, *temp = NULL;
    int size, choice, data, position, element, foundPos;
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

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);
            head = insertAtStart(head, data);
            break;

        case 2:
            printf("Enter Data: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;

        case 3:
            printf("Enter Data: ");
            scanf("%d", &data);
            printf("Enter Position (1 to %d): ", countNodes(head));
            scanf("%d", &position);
            head = insertAtNth(head, position, data);
            break;

        case 4:
            head = deleteStart(head);
            break;

        case 5:
            head = deleteEnd(head);
            break;

        case 6:
            printf("Enter Position (1 to %d): ", countNodes(head));
            scanf("%d", &position);
            head = deleteNth(head, position);
            break;

        case 7:
            printf("Enter Element: ");
            scanf("%d", &element);
            foundPos = searchElement(head, element);
            (foundPos == -1) ? printf("Element Not Found!\n") : printf("Element Found at %d!\n", foundPos);
            break;

        case 8:
            printList(head);
            break;

        case 9:
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
            exit(0);
        }
    }
    return 0;
}