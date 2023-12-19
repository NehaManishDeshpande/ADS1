#include <iostream>

using namespace std;

int Binary(int a[], int left, int right, int n)
{

    while (left <= right)
    {
        int mid = (right + left) / 2 ;
        
        if (a[mid] == n) //the middle one
        {
            return mid;
        }
        else if (a[mid] < n) //the second half
        {
            left = mid + 1;
        }
        else    //the first half
        {
            right = mid - 1;
        }
        
    }

    return -1;
}
int main()
{
    int n;
    int arr[10];

    cout << "Enter the list" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number to search: " << endl;
    cin >> n;

    int output = Binary(arr, 0, 9, n);

    if (output == -1)
    {
        cout << "no match found" << endl;
    }
    else
    {
        cout << "Match found at position " << output << endl;
    }

    return 0;
}
