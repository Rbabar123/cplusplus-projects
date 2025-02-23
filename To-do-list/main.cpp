#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <string> tasks;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. exit\nChoice: ";
        cin >> choice;
        cin.ignore(); // It ignores new line

        switch (choice) {
        case 1:
        cout << "Enter Task: ";
        getline(cin, task);
        tasks.push_back(task);
        break;

        case 2:
            for (int i = 0; i < tasks.size(); i++)
                cout << i + 1 << ". " << tasks[i] << endl;
            break;
        }
    } while (choice !=3);
    return 0;

}
