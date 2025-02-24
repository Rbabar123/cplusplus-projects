#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //Seed the random number genearators

        srand(time(0));
        int secretNumber = rand() % 100 + 1; //random number between 1 and 100
        int guess;
        int attempts = 0;

        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I have selected a number between 1 and 100. Try to guess it!" << endl;

        //Game loop
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            if (guess > secretNumber) {
                cout << "Too high! Try agaim." << endl;
            } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
            } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << "attempts." << endl;
            }
        } while (guess !=secretNumber);
    return 0;
}
