//quick sort

#include<stdio.h>

int count=0;

void swap(int *a, int *b)
{
    count++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot,i,j,temp;
    pivot=a[low];
    i=low;
    j=(high+1);
    do{
        do{
        i++;
        }
        while(a[i] < pivot && i <= high);

        do{
            j--;
        }
        while(a[j] > pivot);

        if(i<j){
            swap( &a[i], &a[j]);
        }
        else{
            swap(&a[j], &a[low]);
        }

    }
    while(i<j);
    
    return j;
}

void QuickSrt(int a[], int low, int high){
    if(low < high){

        int j= partition(a, low, high);
        // printf("\nlow: %d, high: %d, j: %d", low, high, j);
        QuickSrt(a, low, j-1);
        // printf("\nlow: %d, high: %d low wala", low, j-1);
        QuickSrt(a, j+1, high);
        // printf("\nlow: %d, high: %d high wala", j+1, high);
    }
}

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t", a[i]);
    }
}

void main(){
    printf("-----***** Quick Sort *****------ \n");
    int n;
    printf("Enter the Size of array to be sorted:\n");
    scanf("%d", &n);

    printf("Enter the array to be sorted:\n");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Unsorted Array:\n");
    printArray(a, n);

    QuickSrt(a, 0, n-1);

    printf("\nSorted Array with Quick Sort:\n");
    printArray(a, n);

    printf("\nTotal no of swaps are: %d", count);
}