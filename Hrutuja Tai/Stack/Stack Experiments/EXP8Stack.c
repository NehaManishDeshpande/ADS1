//postfix to prefix

/* For  postfix to prefix  traverse from left to right, if operand arraives push it and if operator pop and place the operator before the 2 operands */

#include<stdio.h>
#include<string.h>
#define MAX 100


void toPrefix(char expression[]){
    int top = -1;
    char stack[MAX][MAX], op1[50], op2[50], s[2], prefix[MAX];
    int len = strlen(expression);

    for(int i= 0; i<len; i++){

        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^'){

            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            s[0] = expression[i];
            s[1] = '\0';
            strcpy(prefix, s);
            strcat(prefix, op2);
            strcat(prefix, op1);
            strcpy(stack[++top], prefix);

        }
        else{
            s[0] = expression[i];
            s[1] = '\0';
            strcpy(stack[++top] , s);  
        }
    }
    
    printf("\nPrefix Expression: %s",stack[top]);
}

void main(){
    char expression[] = "ab/c+def*+-";
    printf("\nPostfix Expression: %s", expression);
    toPrefix(expression);
}