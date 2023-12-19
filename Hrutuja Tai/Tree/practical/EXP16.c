// Write a program to efficiently search a perticular employee record by
// using Tree data structure. Also sort the data on emp­id in ascending
// order.


#include<stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct student{
    char name[10];
    int id;
    struct student *left, *right;
}employee;

employee *list[50];
int number = 0;

employee *create(int data, char name[]){
    employee *P = (employee*)malloc(sizeof(employee));
    P->id = data;
    strcpy(P->name, name);
    P->left = P->right = NULL;
    list[number++] = P; 
    return P;
}

employee *Insert(int id, char name[], employee *stud){
    if(stud == NULL){
        return create(id, name);
    }
    else if(id < stud->id){
        stud->left = Insert(id, name, stud->left);
    }
    else if(id > stud->id){
        stud->right = Insert(id, name, stud->right);
    }else{
        return stud;
    }

    return stud;
}

void InsertRollNo(){
    int num = number;
    employee *temp ;

    //bubble sort
    for(int i = 0; i< num; i++){
        for(int j = i+1; j <num; j++){
            if(list[i]->id > list[j]->id){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }



    printf("\nID     Name");
    for(int i = 0; i < num ; i++){
        printf("\n%2d    %4s", list[i]->id, list[i]->name);
    }
}

int main(){
    int n, marks;
    char name[20];
    // printf("\nEnter the number of students: ");
    // scanf("%d", &n);

    employee *root = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("\nEnter the name and marks of student %d: ", i+1);
    //     scanf("%s %d", name, &marks);
    //     root = Insert(marks, name, root);
    // }
    root = Insert(54, "a", root);
    root = Insert(87, "b", root);
    root = Insert(99, "c", root);
    root = Insert(65, "d", root);
    root = Insert(35, "e", root);

    InsertRollNo();
    return 0;
}
