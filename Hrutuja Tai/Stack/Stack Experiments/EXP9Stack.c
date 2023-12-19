// WAP to accept a string of parenthesis and check its validity by using
// stack.


#include<stdio.h>
#include<string.h>
#define MAX 100


int opening(char ch){
    return (ch == '(' || ch == '{' || ch == '[');
}

int closing(char ch){
    return (ch == ')' || ch == '}' || ch == ']');
}

char openingOf(char ch){
    switch(ch){
        case ')': return '(';
                break;
        case ']': return '[';
                break;
        case '}': return '{';
                break;
        default: return'\0';
                break;
    }
}

void checkValidity(char parenthesis[]){
    int top =-1;
    char stack[MAX], p;
    for(int i=0; i<strlen(parenthesis); i++){
        p = parenthesis[i];
        if(opening(p) == 1){
            stack[++top] = p;
            // strcpy(stack[++top], p);
            // p[0] = parenthesis[i];
            // p[1] = '\0';
            // strcpy(stack[++top], p);
        }
        else if (closing(p) == 1){
            if(stack[top] == openingOf(p)){
                stack[top--];
            }
            else{
                break;
            }
            
        }
    }
    if(top == -1){
        printf("\nValid");
    }
    else{
        printf("\nInvalid");
    }
    
}

void main(){
    char parenthesis[] = "(([{([{()}])}]))";
    // char parenthesis[50];
    // printf("\nEnter the parenthesis expression: ");
    // scanf("%s", parenthesis);
    checkValidity(parenthesis);
}