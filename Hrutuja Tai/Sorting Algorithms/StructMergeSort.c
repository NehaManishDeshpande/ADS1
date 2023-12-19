// structure merge sort

#include<stdio.h>
#include<string.h>

int count=0;

typedef struct Employee{
    char name[10];
    int no;
    float salary;
}emp;

void merge(emp a[], int low, int k, int high){
    
    int s1 = k-low+1;
    int s2 = high-k;
    
    emp l1[s1], l2[s2];

    //coping the subarrays to l1 and l2

    for(int x=0; x<s1; x++){
        l1[x] = a[low+x];
    }

    for(int x=0; x<s2; x++){
        l2[x] = a[k+1+x];
    }

    //sorting begins

    int  i=0, j=0, l=low;
    while (i < s1 && j < s2){
        if( l1[i].no < l2[j].no){
            count++;
            a[l]=l1[i];
            i++;
            l++;
        }else{
            count++;
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

void mergeSrt( emp a[], int low, int high){
    if(low < high){
        int k= ((low+high)/ 2);
        mergeSrt ( a, low, k);
        mergeSrt (a, k+1, high);
        merge (a, low, k ,high);
    }
}

void printArray(emp s[], int size){
    for(int i=0;i<size;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].no, s[i].salary);
    }
}

void main(){
    printf("-----***** Structure Merge Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    emp s[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",s[i].name, &s[i].no, &s[i].salary);
    }

    printf("\nUnsorted Array:\n");
    printArray(s, n);

    mergeSrt(s, 0, n);

    printf("\nSorted Array by Merge Sort:\n");
    printArray(s, n);

    printf("\nTotal no of swaps are: %d", count);
}