//WAP to implement following by using stack. A. Factorial of a given
// number B. Generation of Fibonacci series


#include<stdio.h>
#include<malloc.h>

void factorial(int n){
    printf("\n\nEnter the number to find factorial: ");
    scanf("%d", &n);
    int top = -1;
    int stack[50];
    stack[++top] = 1;
    for(int i = 2; i<=n; i++){
        stack[++top] = stack[top] * i;
    }
    printf("\nFactorial of %d is = %d", n, stack[top]);
}

void fibonacci(int n){
    printf("\n\nEnter the Length of the Fibonacci Series: ");
    scanf("%d", &n);
    printf("\nFibonacci Series: ");
    int top = -1;
    int stack[100];
    int f0 = 0, f1 = 1;
    stack[++top] = f0;
    printf("%d ", stack[top]);
    stack[++top] = f1;
    printf("%d ", stack[top]);
    for(int i=2; i<n; i++){
        stack[++top] = f0 + f1;
        printf("%d ", stack[top]);
        f0 = f1;
        f1 = stack[top];
    }
}

void main(){
    int n;
    factorial(n);
    fibonacci(n);
    
}