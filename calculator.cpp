#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char op;

    cout<< "enter The first number: ";
    cin >> num1;
    cout << "nter the second number: ";
    cin >> num2;
    cout << "enter the operator: ";
    cin>> op;



        if (op == '+'){

            cout<< "The sum is: " << num1 + num2 << endl;
        } else if (op =='-')
            {
                cout << "The difference is: " << num1 - num2 << endl;
            } else if ( op == '*')
            {
                cout << "The product is: " << num1 * num2 <<endl;
            } else if (op == '/')
            {
                cout << "The quotient is: " << num1 / num2 << endl;
            } else {

            cout << "Invalid operator." << endl;
            }



    return 0;
}
