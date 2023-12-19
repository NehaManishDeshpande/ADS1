//prefix to postfix
/* For prefix to postfix traverse from right to left, if operand arraives push it and if operator pop and place the operator after the 2 operands */

#include<stdio.h>
#include<string.h>
#define MAX 100


void toPostfix(char expression[]){
    int top = -1, oprandCount=0;
    char stack[MAX][MAX], op1[50], op2[50], s[2], postfix[MAX];
    int len = strlen(expression);

    for(int i= len-1; i>=0; i--){

        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^'){

            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            strcpy(postfix, op1);
            strcat(postfix, op2);
            s[0] = expression[i];
            s[1] = '\0';
            strcat(postfix, s);
            strcpy(stack[++top], postfix);

        }
        else{
            s[0] = expression[i];
            s[1] = '\0';
            strcpy(stack[++top] , s);  
        }
    }
    
    printf("\nPostfix Expression: %s",stack[top]);
}

void main(){
    char expression[] = "-+/abc+d*ef";
    printf("\nPrefix Expression: %s", expression);
    toPostfix(expression);
}