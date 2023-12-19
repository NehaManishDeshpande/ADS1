//heap sort

#include<stdio.h>
int count=0;

typedef struct Employee{
    char name[10];
    int no;
    float salary;
}emp;

void swap(emp *a, emp *b){
    count++;

    emp temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(emp a[], int size, int parent){

    int largestRoot = parent;
    int left = 2 * parent +1;
    int right = 2 * parent +2;

    if (left < size && a[largestRoot].no < a[left].no){
        largestRoot = left;
    }

    if (right  < size && a[largestRoot].no < a[right].no){
        largestRoot = right;
    }

    if( largestRoot != parent){
        swap(&a[parent], &a[largestRoot]);
        heapify(a, size, largestRoot);
    }
}

void heapSrt(emp a[], int size){
    for( int i = size/2 - 1; i >= 0; i--){
           heapify(a, size, i);
    }

    for(int j = size - 1 ; j>=0; j--){
        swap(&a[0], &a[j]);
        heapify(a, j, 0);
    }
}

void printArray(emp a[], int size){
    for(int i=0;i<size;i++){
        printf("%s %d %.2f\n",a[i].name, a[i].no, a[i].salary);
    }
}

void main(){
    printf("-----***** Structure Shell Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    emp a[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",a[i].name, &a[i].no, &a[i].salary);
    }

    printf("\nUnsorted Array:\n");
    printArray(a, n);

    heapSrt(a, n);

    printf("\nSorted Array with Heap Sort:\n");
    printArray(a, n);

    printf("\nTotal no of swaps are: %d", count);
}
