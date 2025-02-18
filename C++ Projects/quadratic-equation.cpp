#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double a, b, c, x1, x2, discriminant;

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;

     if (discriminant == 0){
        cout << "Invalid input! 'a' cannot be zero in a quadeatic equation." << endl;
        return 1;
    }



    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0){
        x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);


    cout << "The quadratic equation is: " << x1 << " and " << x2 << endl;

    } else if (discriminant == 0){

    x1 = -b / (2 *a);
    cout << "The root of the quadratic equation is: " << x1 << endl;

    }





    return 0;
}
