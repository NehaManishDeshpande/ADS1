//infix to postfix
/* For infix to postfix traverse from right ot left if the opening brackets then push and id closing brackets the pop till its respective closing bracket arrives place the operator after the 2 operands*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX 100

int isAlpha(char exp){
    return ((exp >= 'a' && exp <= 'z') || (exp >= 'A' && exp <= 'Z'));
}


int isOperator(char exp){
    return (exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp == '^' );
}


int precedence(char exp){
    if(exp == '^'){
        return 3;
    }
    else if(exp == '/' || exp == '*'){
        return 2;
    }
    else if(exp == '+' || exp == '-'){
        return 1;
    }
    else{
        return 0;
    }
}


char * toPostfix(char *expression){
    int i=0, j=0;
    int len = strlen(expression);
    int top =-1;
    char stack[MAX];
    char *postfix = (char*)malloc(sizeof(char) * (len ));
    while(expression[i] != '\0'){

        //check if operand
        if(isAlpha(expression[i]) == 1){
            postfix[j++] = expression[i];
        }

        //if the input is the bracket
        else if(expression[i] == '('){
            stack[++top] = expression[i];
        }

        //if the input is the closing bracket
        else if(expression[i] == ')'){
            while( top > -1 && stack[top] != '('){
                postfix[j++] = stack[top--];
            }

            if(top > -1 && stack[top] != '('){
                return "Invalid Expression";
            }
            else{
                top--;
            }
        }

        //if the input is operator
        else if(isOperator(expression[i]) == 1){
            while(top > -1 && precedence(expression[i]) <= precedence(stack[top])){
                postfix[j++] = stack[top--];
            }

            stack[++top] = expression[i];
        }

        i++;
    }

    while(top > -1){
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    return postfix;
}


void reverse(char *infix){
    int len = strlen(infix);
    char temp[len];
    int j = len,  i=0;
    temp[j--]='\0';
    while(infix[i] != '\0'){
        temp[j--] = infix[i++];
    }
    strcpy (infix, temp);
}

void bracket(char *bracket){
    for(int i=0; i<strlen(bracket)+1; i++){
        if(bracket[i] == '('){
            bracket[i] = ')';
        }
        else if(bracket[i] == ')'){
            bracket[i] = '(';
        }
    }
}

char *toPrefix(char *infix){
    //1st step reverse
    reverse(infix);
    //2nd step to arrange brackets
    bracket(infix);
    //3rd step to postfix
    char *prefix = toPostfix(infix);
    //4th step to reverse again
    reverse(prefix);

    //return the reversed one
    return (prefix);
}



void main(){
    char expression[] = "((a/b)+c)-(d+(e*f))";
    printf("\nInfix Expression is: %s", expression);
    printf("\nPostfix Expression is: %s", toPostfix(expression));
    printf("\nPrefix Expression is: %s", toPrefix(expression));
}