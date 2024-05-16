// 8 - Postfix To Infix - 06.03.24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure For Stack Node
typedef struct StackNode
{
    char *data;
    struct StackNode *next;
} StackNode;

// Function To Create A New Stack Node
StackNode *createNode(char *data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function To Check If The Given Character Is An Operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function To Convert Postfix Expression To Infix Expression
char *postfixToInfix(char postfix[])
{
    StackNode *stack = NULL;
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            // Operand
            char *operand = (char *)malloc(2 * sizeof(char)); // Allocate Memory For Operand
            operand[0] = postfix[i];
            operand[1] = '\0';
            StackNode *node = createNode(operand);
            node->next = stack;
            stack = node;
        }
        else if (isOperator(postfix[i]))
        {
            // Operator
            char *operand2 = stack->data;
            stack = stack->next;
            char *operand1 = stack->data;
            stack = stack->next;
            // Combine Operand And Operator Into Infix Expression
            char *infix = (char *)malloc((strlen(operand1) + strlen(operand2) + 4) * sizeof(char));
            sprintf(infix, "(%s%c%s)", operand1, postfix[i], operand2);
            StackNode *node = createNode(infix);
            node->next = stack;
            stack = node;
        }
    }
    return stack->data; // Final Infix Expression
}

int main()
{
    char postfix[MAX_SIZE];
    char *infix;
    printf("Enter The Postfix Expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strcspn(postfix, "\n")] = '\0'; // Remove The NewLine Character
    infix = postfixToInfix(postfix);
    printf("Infix Expression: %s\n", infix);
    // Free Memory Allocation For Infix Expression
    free(infix);
    return 0;
}