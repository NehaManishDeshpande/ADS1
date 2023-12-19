//heap sort

#include<stdio.h>

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t", a[i]);
    }
}

void swap(int *a, int *b){
    int temp= *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int size, int parent){

    //largest is the parent and then the index of left and right child is 2*p+1 and 2*p+2
    int largestRoot = parent;
    int left = 2 * parent +1;
    int right = 2 * parent +2;

    printf("\nLargest: %d", a[largestRoot]);
    //fix the parent
    if (left < size && a[largestRoot] < a[left]){
        largestRoot = left;
    }

    if (right  < size && a[largestRoot] < a[right]){
        largestRoot = right;
    }

    if( largestRoot != parent){
        swap(&a[parent], &a[largestRoot]);
        
        heapify(a, size, largestRoot);   //till largest eq to parent
    }
}

//use the binary search tree where the left child is smaller than parent and right child is greater then the parent
void heapSrt(int a[], int size){
    // construct a normal BSt from the elements
    for( int i = size/2 - 1; i >= 0; i--){
           heapify(a, size, i);
        //    printf("\n\n");
        //    printArray(a, size);
    }

    //arrange then in order
    for(int j = size - 1 ; j>=0; j--){
        swap(&a[0], &a[j]);
        // printf("\n*");
        // printArray(a, size);
        heapify(a, j, 0);
        // printf("\n#");
        // printArray(a, size);
    }
}



void main(){
    printf("-----***** Heap Sort *****------ \n");
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

    heapSrt(a, n);

    printf("\nSorted Array with Heap Sort:\n");
    printArray(a, n);
}

/*
Sort: 15 29 45 98 6 2 11 1

size/2 -1 = 3

Pass 1: 45 (l = 11;  r = 1)
pass 2: 29 (l = 6; r= 2)
*/