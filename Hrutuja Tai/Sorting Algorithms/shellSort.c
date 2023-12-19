#include<stdio.h>

int count=0;

void shellSort(int a[], int n){
    int temp;

    for(int gap=n/2; gap>0; gap/=2){

        for(int i=gap; i<n; ++i){
            temp = a[i];
            int j;

            for(j=i; j>=gap && a[j-gap] > temp; j-=gap){
                  count++;
                  a[j] = a[j-gap];
            }

        a[j] = temp;

        }
        
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n ;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main(){
    printf("-----***** Shell Sort *****------ \n");
    int n;
    printf("Enter the size of the Array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array elemets:");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("\n Unsorted Array:\n");
    printArray(a, n);

    shellSort(a, n);

    printf("\n Sorted Array with Shell Sort:\n");
    printArray(a, n);

    printf("\n Number of Swaps are: %d", count);

}