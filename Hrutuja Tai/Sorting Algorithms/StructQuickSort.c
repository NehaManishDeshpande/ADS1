// #include<stdio.h>
// #include<string.h>

// int count=0;

// struct Employee{
//     char name[10];
//     int no;
//     float salary;
// };

// typedef struct Employee emp;

// void compareANDprint(int a[], emp s[], int n){
//     printf("Sorted Array: \n");
//     for(int i=0; i<n; i++){
//        for (int j=0; j<n; j++){
//         if (a[i] == s[j].no){
//             printf("%s %d %.2f \n", s[j].name, s[j].no, s[j].salary);
//         }
//        }
//     }
// }


// void swap(int *a, int *b)
// {
//     count++;
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition(int a[], int low, int high){
//     int pivot,i,j,temp;
//     pivot=a[low];
//     i=low;
//     j=(high+1);
//     do{
//         do{
//         i++;
//         }
//         while(a[i] < pivot && a[i] <= high);

//         do{
//             j--;
//         }
//         while(a[j] > pivot);

//         if(i<j){
//             swap( &a[i], &a[j]);
//         }
//         else{
//             swap(&a[j], &a[low]);
//         }

//     }
//     while(i<j);
    
//     return j;
// }

// void QuickSrt(int a[], int low, int high){
//     if(low < high){
//         int j= partition(a, low, high);
//         QuickSrt(a, low, j-1);
//         QuickSrt(a, j+1, high);
//     }
// }

// void printArray(emp s[], int size){
//     for(int i=0;i<5;i++){
//         printf("%s %d %.2f\n",s[i].name, s[i].no, s[i].salary);
//     }
// }

// void printNo(int a[], int n){
//     for(int i=0; i<n ;i++){
//         printf("%d\t", a[i]);
//     }
// }

// void main(){
//     int n;
//     printf("enter the size:");
//     scanf("%d", &n);
//     emp s[n];
//     int no[n];
//     for(int i=0;i<n;i++){
//         scanf("%s %d %f",s[i].name, &s[i].no, &s[i].salary);
//     }

//     for(int i=0; i<n; i++){
//         no[i]=s[i].no;
//     }

//     printf("Unsorted Array:\n");
//     printArray(s, n);

//     QuickSrt(no, 0, n-1);

//     // printNo(no, n);

//     compareANDprint(no, s, n);  //for comapring and printing no array struct and size

//     printf("\nTotal no of swaps are: %d", count);
// }







// optimized code

#include<stdio.h>
#include<string.h>

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


int partition(emp a[], int low, int high){

    int i,j;
    int  pivot=a[low].no;
    
    i=low;
    j=(high+1);
    do{
        do{
        i++;
        }
        while(a[i].no < pivot && i <= high);

        do{
            j--;
        }
        
        while(a[j].no > pivot);

        if(i<j){
                swap(&a[i], &a[j]);
        }
        else{
                swap(&a[j], &a[low]);
        }

    }
    while(i<j);
    
    return j;
}

void QuickSrt(emp a[], int low, int high){
    if(low < high){
        int j= partition(a, low, high);
        QuickSrt(a, low, j-1);
        QuickSrt(a, j+1, high);
    }
}

void printArray(emp s[], int size){
    for(int i=0;i<size;i++){
        printf("%s %d %.2f\n",s[i].name, s[i].no, s[i].salary);
    }
}


void main(){
    printf("-----***** Structure Quick Sort *****------ \n");
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    emp s[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %f",s[i].name, &s[i].no, &s[i].salary);
    }

    printf("Unsorted Array:\n");
    printArray(s, n);

    QuickSrt(s, 0, n);

    printf("\nSorted Array by Quick Sort:\n");
    printArray(s, n);

    printf("\nTotal no of swaps are: %d", count);
}
