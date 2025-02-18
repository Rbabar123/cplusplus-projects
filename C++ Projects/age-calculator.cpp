#include <iostream>
using namespace std;

int main()
{

    int byear, bday;
    cout << "Enter your birth year: ";
    cin >> byear;


    bday = 2025 - byear;

    if (byear > 2025) {
        cout << "Invalid birth year." << endl;
    } else {cout << "You are " << bday << " years old." << endl; }

    return 0;
}
