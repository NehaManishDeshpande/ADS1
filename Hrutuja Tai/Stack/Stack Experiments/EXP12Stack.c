// Array is given of size 'n'. We need to divide this array in 'm' numbers,
// where 2 < m < n. After division each subarray is treated as a stack. If a
// one stack becomes full we should utilize the space of its next adjacent
// stack. Write a program to simulate above situation

#include<stdio.h>

void divide(int arr[], int n, int m){
    int top = -1, a = 0;
    int stack[m][n];
    for(int i=0; i<n; i++){
        while(m!=0){
            stack[a][++top] = arr[i];
        }
        a+=1;
        top = -1;
    }

    //display{}
    for(int i=0; i<a; i++){
        while(top > -1){
            printf("%d ->", stack[i][top--]);
        }
        top = m;
    }
}

void main(){
    int n, m;
    printf("\nEnter the \'n\' size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the Array Elements: ");
    for(int i=0; i<n ; i++){
        scanf("%d", arr[i]);
    }

    printf("\nEnter the \'m\' parts in which the array has to br divided (2<m<n): ");
    scanf("%d", &m);

    divide(arr, n, m);
}