#include <iostream>
using namespace std;

int main()
{

    int num, reverseNum;

    cout << "Enter a three digit number: ";
    cin >> num;

    while(num > 0){
        int digit = num % 10;
        reverseNum = (reverseNum * 10)+digit;
        num /= 10;


    }
       cout << "Revered number: " << reverseNum << endl;
    return 0;
}
