//postfix to infix
/* for postfix to infix traverse from left to right, if operand arrives push and if operator pop and place operator in between ( operand 1 operator operand 2 )*/

#include<stdio.h>
#include<string.h>
#define MAX 100

void toInfix(char expression[]){
    int top=-1;
    char stack[MAX][MAX], infix[MAX], op1[50], op2[50],s[2];
    int len = strlen(expression);
    for(int i = 0; i< len; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^'){

            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            strcpy(infix, "(");
            strcat(infix, op2);
            s[0] = expression[i];
            s[1] = '\0';
            strcat(infix, s);
            strcat(infix, op1);
            strcat(infix, ")");
            strcpy(stack[++top], infix);
        }
        else{
            s[0] = expression[i];
            s[1] = '\0';
            strcpy(stack[++top] , s);
        }
    }
    printf("\nInfix Expression: %s",stack[top]);
}

void main(){
    char expression[] = "ab/c+def*+-";
    printf("\nPostfix Expression: %s", expression);
    toInfix(expression);
}