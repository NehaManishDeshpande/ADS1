// WAP to accept a string from user and perform following operations on it
// using stacks. A. Palindrome B. String Reverse C. String Concat D.String
// compare

#include<stdio.h>
#include<string.h>

#define MAX 100
// int top =-1;
// char stack[MAX];

void reverse(char *str){
    int len = strlen(str);
    int top =-1;
    char stack[len];
    int j=0, i = 0;

    //put in the stack
    while(str[i] != '\0'){
        stack[++top] = str[i++];
    }

    char reverse[len];
    reverse[j++] = '\0';

    //remove out of stack
    while(str[i] != '\0'){
        reverse[j++] = stack[top--];
    }

    printf("\nThe reversed String is: %s", reverse);
}

void compare(char *str1, char *str2){
    int i=0;
    int len = strlen(str1);
    int top =-1;
    char stack[len];
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] == str2[i]){
            stack[++top] = str1[i];
        }
        i++;
    }
    if(stack[top] == len){
        printf("\nStrings are Equal");
    }
    else{
        printf("\nStrings are Equal");
    }
}

void  palidrome(char *str){
    int len = strlen(str);
    int top =-1;
    char stack[len+1];
    int j=0, i = 0;
    char temp[0];

    //put in the stack
    while(str[i] != '\0'){
        stack[++top] = str[i++];
    }

    //remove out of stack
    while(str[i] != '\0'){
        temp[j++] = stack[top--];
    }

    if(str == temp)
       printf("\nStrings are Palidrome");
    else
       printf("\nStrings are not Palidrome");
}

void concat(char *str1, char *str2){
    int top =-1;
    char stack[MAX];
    int i=0;
    while (str1[i++] != '\0')
    {
        stack[++top] = str1[i];
    }
    i = 0;
    while (str2[i++] != '\0')
    {
        stack[++top] = str2[i];
    }

    printf("\nConcated String is: ");
    for (int j  = strlen(str1) + strlen(str2); j >=0; j--)
    {
        printf("%s", stack[top--]);
    }
}

void main(){
    char str[MAX];
    strcpy(str, "malayalam");
    printf("\nEnter the String:");
    // scanf("%s", str);
    printf("%s", str);

    // palidrome(str);
    reverse(str);

    // printf("\nEnter the Second String to concat:");
    // char str2[MAX];
    // strcpy(str2, "hrutuja");
    // // scanf("%s", str2);
    // printf("%s", str2);

    // compare(str, str2);
    // concat(str, str2);
}