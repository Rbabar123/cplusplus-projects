#include <iostream>
using namespace std;

int main()
{

    int a[] = {4, 8, 5, 9, 0, 2, 7, 3, 6, 1};

    int length = 10;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

    }


        for (int i = 0; i < length; i++)
        {

            cout << a[i] << " ";
        }
        cout << endl << endl;
    return 0;
}
