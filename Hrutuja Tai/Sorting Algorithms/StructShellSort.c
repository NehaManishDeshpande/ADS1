// structure Shell sort

#include<stdio.h>

int count=0;

typedef struct Employee{
    char name[10];
    int no;
    float salary;
}emp;

void shellSort(emp a[], int n){
    emp temp;

    for(int gap=n/2; gap>0; gap/=2){

        for(int i=gap; i<n; ++i){
            temp = a[i];
            int j;

            for(j=i; j>=gap && a[j-gap].no > temp.no; j-=gap){
                  count++;
                  a[j] = a[j-gap];
            }

        a[j] = temp;

        }
        
    }
}

void printArray(emp s[], int size){
    for(int i=0;i<size;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].no, s[i].salary);
    }
}

void main(){
    printf("-----***** Structure Shell Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    emp s[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",s[i].name, &s[i].no, &s[i].salary);
    }

    printf("\nUnsorted Array:\n");
    printArray(s, n);

    shellSort(s, n);

    printf("\nSorted Array by Shell Sort:\n");
    printArray(s, n);

    printf("\nTotal no of swaps are: %d", count);
}