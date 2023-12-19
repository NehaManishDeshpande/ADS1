//insertion sort

#include<stdio.h>

int count=0;

void swap(int *a, int *b){
    count++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertSort(int a[], int n){
    int i, key, j;
    for(i=1; i<n; i++){
        key= a[i];
        j=i-1;

        while(j>=0 && a[j] > key){
            swap(&a[j+1], &a[j]);
            j= j - 1;
        }
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n ; i++){
        printf("%d \t", a[i]);
    }
}

void main(){
    printf("-----***** Insertion Sort *****------ \n");
    int n;
    printf("Enter the size of the Array:\n");
    scanf("%d", &n);

    printf("Enter the Array elements:\n");
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d" , &a[i]);
    }

    printf("\n Unsorted Array:\n");
    printArray(a, n);

    insertSort(a, n);

    printf("\n Sorted Array with insertion sort:\n");
    printArray(a, n);

    printf("\nThe total no of swaps are: %d", count);

}