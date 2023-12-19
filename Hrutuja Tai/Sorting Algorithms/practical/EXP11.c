// You hav e a fleet of N cars waiting for repair, with the estimated repair
// times rk for the car Ci , 1 ? k ? N. What is the best repairschedule (order
// of repairs) to minimize the total lost time for being out­of­service. How
// much computation is needed to find the lost service­times all schedules?

#include<stdio.h>
#define r 15

typedef struct repairCar{
    char CarNo[5];
    int repairTime;
}car;

void printOrder(car head[], int n){
    printf("\nBest Repair Schedule: ");
    for(int i = 0; i < n; i++){
        printf("\n%s -> (time) %d min",  head[i].CarNo, head[i].repairTime);
    }
}


void merge(car head[], int low, int k, int high){
    int s1, s2;
    s1 = k-low+1;
    s2 = high - k;
    car l1[s1], l2[s2];

    for(int i = 0; i < s1; i++){
        l1[i] = head[low + i];
    }

    for(int i = 0; i < s2; i++){
        l2[i] = head[k+1+i];
    }

    int i = 0, j = 0, l = low;
    while(i < s1 && j <s2){
        if(l1[i].repairTime < l2[j].repairTime){
            head[l] = l1[i];
            i++;
            l++;
        }else{
            head[l] = l2[j];
            j++;
            l++;
        }
    }
    while (i < s1){
        head[l] = l1[i];
        i++;
        l++;
    }
    while (j < s2){
        head[l] = l2[j];
        j++;
        l++;
    }
}

void mergeSrt(car head[], int low, int high){
    if(low < high){
        int k = ((low + high) / 2);
        mergeSrt(head, low, k);
        mergeSrt(head, k+1, high);
        merge(head, low, k, high);
    }
}

void carIN(car head[], int n){
    printf("\nEnter the Number of cars for Repair: ");
    scanf("%d", &n);
    int time;

    for(int i = 0; i < n; i++){
        printf("\nEnter the car no to be Repaired: ");
        scanf("%s", head[i].CarNo);
        printf("\nEnter the time required for the  car to be Repaired: ");
        scanf("%d", &time);
        head[i].repairTime = r * time;
    }

    mergeSrt(head, 0, n);

    printOrder(head, n);
}

void main(){
    int n;
    car head[n];
    carIN(head, n);
}