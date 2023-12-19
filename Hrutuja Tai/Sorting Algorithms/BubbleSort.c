#include<stdio.h>

//compare the neighboring element and but the element in the right position
//time complexity id  O(n2)
void bubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t", a[i]);
    }
}

void main(){
    printf("-----***** Bubble Sort *****-----");
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

    bubbleSort(a,  n);

    printf("\nSorted Array with Bubble Sort:\n");
    printArray(a, n);
}

/*
Sort: 15 29 45 98 6 2 11 1

pass 1: 15 29 45 6 2 11 1 98
pass 2: 15 29 6 2 11 1 45 98
pass 3: 15 6 2 11 1 29 45 98
pass 4: 6 2 11 1 15 29 45 98
pass 5: 2 6 11 1 15 29 45 98
pass 6: 2 6 1 11 15 29 45 98
pass 7: 2 1 6 11 15 29 45 98
pass 8: 1 2 6 11 15 29 45 98
*/