#include<iostream>
using namespace std;

//Linear search algorithm
void linear(int a[] , int n)
{
    int temp = -1;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << i << " is the location of element which found in list" << endl;
            temp = 0;
        }
        
    }
    if (temp == -1)
    {
        cout << "element not found" << endl;
    }
    
}
int main()
{
   // int arr[5] = {20, 55, 60, 40, 70};
    int n;
    int arr[5];

    cout << "Enter five element : " << endl;
    for (int i = 0; i < 5; i++)
    {
       cin >> arr[i];
    }
    

    cout << "Enter element which you want : " << endl;
    cin >> n;

    linear(arr, n);
    
    return 0;
}