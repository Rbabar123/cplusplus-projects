#include <iostream>
#include <iomanip>
using namespace std;


int main() {

double height, weight, bmi;
cout << fixed << setprecision(2)<< endl;
cout << "Enter your height: ";
cin >> height;
cout << "Enter your weight:(kg) ";
cin >> weight;

bmi = weight / ((height /100) * (height/100));

if (bmi < 18.5) {
    cout << "You are underweight.";
    cout << bmi << endl;
} else if (bmi >= 18.5 && bmi <=24.9){
    cout << "You have normal weight." << endl;
    cout << bmi << endl;
} else if (bmi >=25 && bmi <=29.9){
    cout << "You are overweight." << endl;
    cout << bmi << endl;
} else {
    cout << "You are obese" << endl;
    cout << bmi << endl;
    }

return 0;
}
