#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{

int c = time(0);
    srand(c);

    cout <<rand() % 3 << endl;
    cout << rand() % 3 << endl;
    return 0;
}
