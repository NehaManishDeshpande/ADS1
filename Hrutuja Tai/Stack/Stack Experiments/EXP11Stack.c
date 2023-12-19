// A person is living in house having 5 rooms. These rooms are adjacent to
// each other. There is a treasure which is electronically locked and to
// unlock it we need a code. In last room there is a box in which some
// decimal number is written. We need to convert that number into binary
// to open treasure which is kept in room no.1 . We need to move from
// room no.1 to 2 to 3 and so on and follow the reverse way to come back
// i.e. from 5 to 4 to 3 etc. Apply suitable logic to implement this scenario
// by using stacks.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void toBinary(int decimal){
    int top = -1;
    int stack[100], bin;
    while(decimal!= 0){
        bin = decimal;
        stack[++top] = bin % 2;
        decimal = decimal / 2;
    }
    printf("\nBinary code is: ");
    while(top>-1){
        printf("%d", stack[top--]);
    }
}

void traverse(int code){
    int room = 1, top = -1;
    int stack[5];

    for(int i=0; i<=5; i++){
        //go from room 1 to 5 to take code
        if(stack[top] == 5){
            printf("\n\nCode in decimal is: %d", code);
            toBinary(code);
            break;
        }
        else{
            stack[++top] = room++;
            printf("\nIn Room %d", stack[top]);
            printf("\n|\nv");
        }
    } 

    printf("\n\n\n****************************************");
    printf("\nFound Code now unlock the treasure");
    printf("\n****************************************\n\n\n");

    int j=5;
    while(j--){
        if(stack[top] == 1){
            printf("\nIn Room %d", stack[top]);
            printf("\nTreasure Unlocked");
            break;
        }
        else{
            printf("\nIn Room %d", stack[top--]);
            printf("\n|\nv");
        }
    }   
}

void main(){
    int code;
    printf("\nEnter the code in decimal: ");
    scanf("%d", &code);
    traverse(code);
}