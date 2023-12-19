#include<stdio.h>

int count=0;

void swap(int *a, int *b){
    count++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n){
    int smallest;
    for(int i=0; i<n ;i++){
        smallest= i;
        
        for(int j=i; j<n; j++){
            if(a[smallest] > a[j]){
                smallest = j;
            }
        }
        swap(&a[i], &a[smallest]);
    } 
}

void printArray(int a[], int n){
    for(int i=0; i<n ;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main(){
    printf("-----***** Selection Sort *****------ \n");
    int n;
    printf("Enter the size of the Array:");
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("\n Unsorted Array:\n");
    printArray(a, n);

    selectionSort(a, n);

    printf("\n Sorted Array with Selection Sort:\n");
    printArray(a, n);

    printf("\n Number of Swaps are: %d", count);

}

