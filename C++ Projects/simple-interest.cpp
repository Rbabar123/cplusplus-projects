#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //delcaring the variables
    double pa, ar, time, si, total;
//pa as Principal Value
//ar as Annual interest Rate (%)
//Time as Time (in years)
    cout << "Enter principal amount: ";
    cin >> pa;
    cout << "Enter annual rate (%): ";
    cin >> ar;
    cout << "Enter time (year): ";
    cin >> time;


    si = (pa * ar * time) / 100; //This is the formula of Simple Interest.
    total = pa + si; // This is the formula of Total Amount.


    cout << fixed << setprecision(2) << endl; //Set the decimal numbers into 2
    cout << "Simple interest: " << si << endl;
    cout << "Total Amount: " << total << endl;

    return 0;
}
