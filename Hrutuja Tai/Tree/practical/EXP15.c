// // Write a program, using trees, to assign the roll nos. to the students of
// // your class as per their previous years result. i.e topper will be roll no. 1.


#include<stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct student{
    char name[10];
    int marks;
    int rollNo;
    struct student *left, *right;
}student;

student *list[50];
int number = 0;

student *create(int data, char name[]){
    student *P = (student*)malloc(sizeof(student));
    P->marks = data;
    strcpy(P->name, name);
    P->rollNo = 0;
    P->left = P->right = NULL;
    list[number++] = P; 
    return P;
}

student *Insert(int marks, char name[], student *stud){
    if(stud == NULL){
        return create(marks, name);
    }
    else if(marks < stud->marks){
        stud->left = Insert(marks, name, stud->left);
    }
    else if(marks > stud->marks){
        stud->right = Insert(marks, name, stud->right);
    }else{
        return stud;
    }

    return stud;
}

void InsertRollNo(){
    int num = number;
    student *temp ;

    //bubble sort
    for(int i = 0; i< num; i++){
        for(int j = i+1; j <num; j++){
            if(list[i]->marks > list[j]->marks){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    for(int i = 0; i <num; i++){
        list[i]->rollNo = number--;
    }

    printf("\nRoll. no     Name     Marks");
    for(int i = num-1; i >=0; i--){
        printf("\n  %5d    %4s   %7d", list[i]->rollNo, list[i]->name, list[i]->marks);
    }
}

int main(){
    int n, marks;
    char name[20];
    // printf("\nEnter the number of students: ");
    // scanf("%d", &n);

    student *root = NULL;
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
