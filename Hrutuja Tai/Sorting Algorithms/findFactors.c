#include<stdio.h>

void main(){
    int n=0;
	// printf("%d", n+=1);
    // printf("%d", 2&3);
    // printf("%d", 2|3);
    // printf("%d", 2^3);
    int min, i=2, j=2;
    min= i<j?i:j;
    printf("%d", min);
    // printf("Enter the number to find from which no it is divisible with:\n");
    // scanf("%d", &n);

    // printf("%d is divisible by:\t", n);
    // for(int i=1; i<=n; i++){
    //     if(n % i == 0){
    //         printf("%d\t", i);
    //     }
    // }
}


// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// int main()
// {
	
//     int num1, num2;
//     scanf("%d %d\n", &num1, &num2);
//     float n1, n2;
//     scanf("%f %f\n", &n1, &n2);
    
//     printf("%d %d\n", (num1+num2), abs(num1-num2));
//     printf("%.1f %.1f\n", (n1+n2), (n1-n2));
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// struct triangle
// {
// 	int a;
// 	int b;
// 	int c;
// };

// typedef struct triangle triangle;

// void swap (int *a, int *b){
//     int temp =*a;
//     *a = *b;
//     *b = temp;
// }

// double calArea(int a, int b, int c){
//     double p = (a+b+c)/2;
//     return sqrt(p * (p-a) * (p-b) * (p-c));
// }
// void sort_by_area(triangle* tr, int n) {
// 	/**
// 	* Sort an array a of the length n
// 	*/
//     int area[n];
//     for (int i=0; i<n; i++){
//         area[i]=calArea(tr[i].a, tr[i].b, tr[i].c);
//     }
//     for (int j=0; j<n ;j++){
//         for (int k=j+1; k<n; k++){
//             if(area[j] > area[k]){
//             swap (&tr[j].a, &tr[k].a);
//             swap (&tr[j].b, &tr[k].b);
//             swap (&tr[j].c, &tr[k].c);
//         }
//         }
//     }
// }

// int main()
// {
// 	int a,b,n;
// 	// scanf("%d", &n);
// 	// triangle *tr = malloc(n * sizeof(triangle));
// 	// for (int i = 0; i < n; i++) {
// 		scanf("%d%d%d", &a, &b, &n);
//         double res=calArea(a,b,n);
//         printf("%.2f",res);
// 	// }
// 	// sort_by_area(tr, n);
// 	// for (int i = 0; i < n; i++) {
// 	// 	printf("\n%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
// 	// }
// 	// return 0;
// }