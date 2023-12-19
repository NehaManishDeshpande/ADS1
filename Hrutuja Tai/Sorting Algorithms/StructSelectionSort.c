// optimized code

#include<stdio.h>
#include<string.h>

int count=0;

struct Employee{
    char name[10];
    int no;
    float salary;
};

typedef struct Employee emp;

void swap(emp *a, emp *b){
    count++;

    emp temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(emp a[], int n){
    int smallest;
    for(int i=0; i<n ;i++){
        smallest= i;
        
        for(int j=i; j<n; j++){
            if(a[smallest].no > a[j].no){
                smallest = j;
            }
        }
        swap(&a[i], &a[smallest]);
    } 
}

void printArray(emp s[], int size){
    for(int i=0;i<size;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].no, s[i].salary);
    }
}


void main(){
    printf("-----***** Structure Selection Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    emp s[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",s[i].name, &s[i].no, &s[i].salary);
    }

    printf("\nUnsorted Array:\n");
    printArray(s, n);

    selectionSort(s, n);

    printf("\nSorted Array by Selection Sort:\n");
    printArray(s, n);

    printf("\nTotal no of swaps are: %d", count);
}
