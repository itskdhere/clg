#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if the given character is an operator
int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//  Function to get the precedence of an operator
int getPrecedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
  int i, j;
  char stack[MAX_SIZE];
  int top = -1;
  for (i = 0, j = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] == ' ')
      continue;
    else if (isalnum(infix[i]))
      postfix[j++] = infix[i];
    else if (infix[i] == '(')
      stack[++top] = infix[i];
    else if (infix[i] == ')')
    {
      while (top != -1 && stack[top] != '(')
      {
        postfix[j++] = stack[top--];
      }
      top--; // Pop '('
    }
    else if (isOperator(infix[i]))
    {
      while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i]))
      {
        postfix[j++] = stack[top--];
      }
      stack[++top] = infix[i];
    }
  }
  while (top != -1)
  {
    postfix[j++] = stack[top--];
  }
  postfix[j] = '\0'; // Null terminate the expression
}

int main()
{
  char infix[MAX_SIZE];
  char postfix[MAX_SIZE];
  printf("Enter the infix expression: ");
  fgets(infix, MAX_SIZE, stdin);
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s", postfix);
  return 0;
}
