// Normally we write our name in order of First name, Middle name and
// Surname. We need to accept these three words in a single string. Write a
// program to arrange these three words in order of Surname, First name
// and Middle name using stack only.


#include<stdio.h>
#include<string.h>

void standard(char name[]){
    int top = -1;
    char stack[10][50];
    char *temp = strtok(name, " ");
    while(temp  != NULL){
        strcpy(stack[++top], temp);
        temp = strtok(NULL, " ");
    }
    char standard[50], Fname[10], middle[10];
    strcpy(standard, stack[top--]);
    strcat(standard, " ");
    strcpy(middle, stack[top--]);
    strcpy(Fname, stack[top--]);
    strcat(standard, Fname);
    strcat(standard, " ");
    strcat(standard, middle);
    printf("\nThe Standard Format : %s", standard);
}
void main(){
    // char name[50] = "A S D";
    char name[50] = "Hrutuja Pandurang Mirgal";
    printf("\nEnter the Name in the format of Name Middle Surname: %s", name);
    // scanf("%s",name);
    standard(name);
}