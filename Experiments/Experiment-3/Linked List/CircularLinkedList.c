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
    Node *temp = head;
    int numberOfNodes = 0;
    while (temp->next != head)
    {
        numberOfNodes++;
        temp = temp->next;
    }
    return numberOfNodes;
}

Node *insertAtStart(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    printf("%d Inserted!\n", data);
    return head;
}

Node *insertAtNth(Node *head, int position, int data)
{
    if (position == 1)
    {
        return insertAtStart(head, data);
    }
    Node *newNode, *temp = head;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
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
    Node *newNode, *temp = head;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    printf("\n%d Inserted!", data);
    return head;
}

Node *deleteStart(Node *head)
{
    if (!head)
    {
        printf("\nLinked List Empty!\n\n");
        return head;
    }
    if (head->next == head)
    {
        head = NULL;
        return head;
    }
    Node *currentNode = head, *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = currentNode->next;
    temp->next = head;
    free(currentNode);
    currentNode = NULL;
    printf("Node Deleted!\n");
    return head;
}

Node *deleteNth(Node *head, int position)
{
    if (!head)
    {
        printf("\nLinked List Empty!\n\n");
        return head;
    }
    if (position == 1)
    {
        return deleteStart(head);
    }
    Node *currentNode = head, *previousNode = head;
    while (position != 1)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
        position--;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    printf("Node Deleted!\n");
    return head;
}

Node *deleteEnd(Node *head)
{
    if (!head)
    {
        printf("\nLinked List Empty!\n\n");
        return head;
    }
    if (head->next == head)
    {
        head = NULL;
        return head;
    }
    Node *currentNode = head, *temp = head;
    while (currentNode->next != head)
    {
        temp = currentNode;
        currentNode = currentNode->next;
    }
    temp->next = currentNode->next;
    free(currentNode);
    printf("Node Deleted!\n");
    return head;
}

int searchElement(Node *head, int element)
{
    Node *temp = head;
    int position = 0;
    while (temp->next != head)
    {
        position++;
        if (temp->data == element)
            return position;
        temp = temp->next;
    }
    return -1;
}

void printList(Node *head)
{
    Node *temp = head;
    if (!temp)
    {
        printf("\nLinked List Empty!\n\n");
        return;
    }
    printf("Your Linked List: \n");

    while (temp->next != head)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
    printf("|%d|", temp->data);
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
    Node *head = NULL, *temp = NULL, *newNode;
    int size, choice, data, position, element, foundPos;
    printf("Enter Size of Cicular Linked List: ");
    scanf("%d", &size);
    while (size--)
    {
        if (!head)
        {
            newNode = createNode();
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = createNode();
            temp->next->next = head;
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