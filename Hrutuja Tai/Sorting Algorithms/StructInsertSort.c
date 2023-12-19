// struct insertion sort

#include<stdio.h>

int count=0;


typedef struct Student{
    char name[10];
    int roll;
    float cpi;
}student;

void swap(student *a, student *b){
    count++;
    student temp = *a;
    *a = *b;
    *b = temp;
}

void insertSort(student a[], int n){
    int i, key, j;
    for(i=1; i<n; i++){
        key= a[i].roll;
        j=i-1;

        while(j>=0 && a[j].roll > key){
            swap(&a[j+1], &a[j]);
            j= j - 1;
        }

        key = a[j+1].roll;
    }
}

void printArray(student s[], int n){
    for(int i=0;i<n;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].roll, s[i].cpi);
    }
}

void main(){
    printf("-----***** Structure Insertion Sort *****------ \n");
    int n;
    printf("Enter the size of the Array:\n");
    scanf("%d", &n);

    printf("Enter the Array elements:\n");
    student a[n];

    for(int i=0; i<n; i++){
        scanf("%s %d %f",a[i].name, &a[i].roll, &a[i].cpi);;
    }

    printf("\n Unsorted Array:\n");
    printArray(a, n);

    insertSort(a, n);

    printf("\n Sorted Array by Insertion Sort:\n");
    printArray(a, n);

    printf("\nThe total no of swaps are: %d", count);

}