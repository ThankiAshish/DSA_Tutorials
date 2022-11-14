#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

struct Stack
{
    int top;
    int capacity;
    char *array;
} typedef Stack;

Stack *createStack(int capacity)
{
    Stack *S = malloc(sizeof(capacity));
    if (!S)
        return NULL;

    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));

    if (!S->array)
        return NULL;
    return S;
}

int isEmpty(Stack *stack) { return stack->top == -1; }

char peek(Stack *stack) { return stack->array[stack->top]; }

char pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];

    return '$';
}

void push(Stack *stack, char element)
{
    stack->array[++stack->top] = element;
    return;
}

int checkForOperator(char character)
{
    switch (character)
    {
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
        return 1;
    }
    return 0;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int validExpression(char expression[])
{
    int openingBrkts = 0, closingBrkts = 0;
    int validExpressionOne = 0, validExpressionTwo = 0;
    for (int i = 0; i < strlen(expression); i++)
    {
        if (checkForOperator(expression[i]) || isOperand(expression[i]))
            validExpressionOne = 1;
    }

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(')
            openingBrkts++;
        if (expression[i] == ')')
            closingBrkts++;
    }

    if (openingBrkts == closingBrkts)
        validExpressionTwo = 1;

    if (validExpressionOne && validExpressionTwo)
        return 1;

    return 0;
}

int operatorPriority(char operator)
{
    switch (operator)
    {
    case '^':
        return 3;

    case '*':
    case '/':
        return 2;

    case '+':
    case '-':
        return 1;
    }
    return -1;
}

int infixToPostfix(char *exp)
{
    int i, k;
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }

        else
        {
            while (!isEmpty(stack) &&
                   operatorPriority(exp[i]) <= operatorPriority(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s", exp);
    return -1;
}

int main()
{
    char expression[MAX];
    printf("Enter Your Infix Expression [MAX: 256 Chars]: ");
    scanf("%s", expression);
    printf("\n");
    if (validExpression(expression))
        infixToPostfix(expression);
    else
        printf("\nInvalid Expression!");
    return 0;
}