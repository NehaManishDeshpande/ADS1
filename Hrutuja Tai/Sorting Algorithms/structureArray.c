#include<stdio.h>
#include<string.h>

int count=0;

struct Student{
    char name[10];
    int roll;
    float cpi;
};

void swap(struct Student *a, struct Student *b){
    count++;

    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Student s[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].roll > s[j].roll){
                swap(&s[i], &s[j]);
            }
        }
    }
}

void printArray(struct Student s[], int n){
    for(int i=0;i<n;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].roll, s[i].cpi);
    }
}

void main(){
    printf("-----***** Structure Bubble Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    struct Student s[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",s[i].name, &s[i].roll, &s[i].cpi);
    }

    printf("\n Unsorted Arrays:\n");
    printArray(s, n);

    bubbleSort(s, n);

    printf("\n Sorted Arrays by bubble Sort:\n");
    printArray(s, n);

    printf("\n Number of Swaps:%d\n", count);

}