//merge sort

#include<stdio.h>

void merge(int a[], int low, int k, int high){
    
    int s1 = k-low+1;
    int s2 = high-k;
    printf("\ns1: %d, s2: %d",s1, s2);
    int l1[s1], l2[s2];

    for(int x=0; x<s1; x++){
        l1[x] = a[low+x];
    }

    for(int x=0; x<s2; x++){
        l2[x] = a[k+1+x];
    }

    int  i=0, j=0, l=low;
    while (i < s1 && j < s2){
        if( l1[i] < l2[j]){
            a[l]=l1[i];
            i++;
            l++;
        }else{
            a[l]=l2[j];
            j++;
            l++;
        }
    }

    while (i < s1){
        a[l]=l1[i];
            i++;
            l++;
    }

    while (j < s2){
        a[l]=l2[j];
            j++;
            l++;
    }
}

void mergeSrt( int a[], int low, int high){
    if(low < high){
        int k= ((low+high)/ 2);
        // printf("\nK= %d", k);
        mergeSrt ( a, low, k);
        // printf("\nlower");
        mergeSrt (a, k+1, high);
        // printf("\nHigher");
        merge (a, low, k ,high);
        // printf("\nMerging");
    }
    // int k= ((low+high)/ 2);
    // merge (a, low, k ,high);
}

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t", a[i]);
    }
}

void main(){
    printf("-----***** Merge Sort *****------ \n");
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

    mergeSrt(a, 0, n);

    printf("\nSorted Array with Merge Sort:\n");
    printArray(a, n);
}