#include <iostream>
using namespace std;

int main()
{
    int a[] = {2, 7, 11, 15};

    for(int i = 0; i <= 4; i++)
    {
        for(int j = 0; j <= 4; j++)
        {
            if(a[i] + a[j] == 9)
            {
                cout << "[ " <<a[i] << " , " << a[j] << " ]" << endl;
            }
        }   
    }
    return 0;
}