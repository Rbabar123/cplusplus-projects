#include <iostream>
using namespace std;

class BankAccount {
private:
	double balance;

public:
	BankAccount() {
		balance = 0.0; // initial balance
	}

	void deposit(double amount) {

		if (amount > 0) {
			balance += amount;
			cout << "Deposite successful! New balance: " << balance << endl;
		}
		else {
			cout << "Invalid deposit amount!" << endl;
		}
	}



void withdraw(double amount) {
	if (amount > 0 && amount <= balance) {

		balance -= amount;
		cout << "Withdrawal successful! New balance: " << balance << endl;
	}
	else {
		cout << "Insufficient balance or invalid amount!" << endl;
	}

}

void checkBalance() {
	cout << "Current balance: " << balance << endl;
}

};

int main() {
	BankAccount myAccount;
	int choice;
	double amount;

	do {
		cout << "\nBank Account System\n";
		cout << "1. Deposit Money\n";
		cout << "2. Withdraw Money\n";
		cout << "3. Check Balance\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter deposit amount: ";
			cin >> amount;
			myAccount.deposit(amount);
			break;
		case 2:
			cout << "Enter deposit amount: ";
			cin >> amount;
			myAccount.withdraw(amount);
			break;
		case 3:
			myAccount.checkBalance();
			break;
		case 4:
			cout << "Thank you for using the bank system. Goodbye!\n";
			break;
		default:
			cout << "Invalid choice! Try again.\n";
			break;
		}
	} while (choice != 4);
	return 0;

}
