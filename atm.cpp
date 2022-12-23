#include <iostream>
using namespace std;

int accNum = 280303;
int pinNumber = 123456789;
int bal = 0;

bool login()
{

	int userAccNum = -1;
	int userPinNum = -1;
	bool accInvalid = true;
	bool pinInvalid = true;

	cout << "Welcome! to Our Bank" << endl;
	cout << "We are here to provide you the best of services!!" << endl;

	while (accInvalid)
	{
		cout << "Please enter your account number: ";
		cin >> userAccNum;

		if (userAccNum == accNum)
		{
			accInvalid = false;
		}
		else
		{
			cout << "You have entered an invalid account number! Please try again." << endl;
		}
	}

	while (pinInvalid)
	{

		cout << "Enter your PIN: ";
		cin >> userPinNum;

		if (userPinNum == pinNumber)
		{
			pinInvalid = false;
		}
		else
		{
			cout << "You have entered an invalid PIN number! Please try again." << endl;
		}
	}

	return true;
}

int getUserOption()
{

	int choice = -1;

	cout << "Services offered:" << endl;
	cout << "1 - View balance" << endl;
	cout << "2 - Withdraw money" << endl;
	cout << "3 - Deposit money" << endl;
	cout << "4 - Exit" << endl;
	cout << "Enter a choice: " << endl;
	cin >> choice;

	return choice;
}

void viewBalance()
{

	cout << "You have:" << endl;
	cout << "Rs " << bal << endl;
}

void withdrawMoney()
{

	int choice = -1;
	int withdrawAmount = 0;
	bool isNotFinished = true;

	do
	{

		cout << "Withdrawal options:" << endl;
		cout << "1 - Rs 50" << endl;
		cout << "2 - Rs 100" << endl;
		cout << "3 - Rs 200" << endl;
		cout << "4 - Rs 500" << endl;
		cout << "5 - Rs 1000" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "choose a withdrawal option" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			withdrawAmount = 50;
			break;
		case 2:
			withdrawAmount = 100;
			break;
		case 3:
			withdrawAmount = 200;
			break;
		case 4:
			withdrawAmount = 500;
			break;
		case 5:
			withdrawAmount = 1000;
			break;
		case 6:
			isNotFinished = false;
			break;
		default:
			cout << "Invalid option! Please Try again." << endl;
			break;
		}

		if (withdrawAmount != 0)
		{
			if (withdrawAmount > bal)
			{
				cout << "You just have a balance of Rs" << bal << ". You cannot withdraw Rs" << withdrawAmount << endl;
			}
			else
			{
				bal = bal - withdrawAmount;
				isNotFinished = false;
			}
			withdrawAmount = 0;
		}

	} while (isNotFinished);
}

void depositMoney()
{

	int choice = -1;
	bool isNotFinished = true;

	do
	{

		cout << "Deposit options:" << endl;
		cout << "1 - Rs 50" << endl;
		cout << "2 - Rs 100" << endl;
		cout << "3 - Rs 200" << endl;
		cout << "4 - Rs 500" << endl;
		cout << "5 - Rs 1000" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "choose a deposit option" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			bal = bal + 50;
			isNotFinished = false;
			break;
		case 2:
			bal = bal + 100;
			isNotFinished = false;
			break;
		case 3:
			bal = bal + 200;
			isNotFinished = false;
			break;
		case 4:
			bal = bal + 500;
			isNotFinished = false;
			break;
		case 5:
			bal = bal + 1000;
			isNotFinished = false;
			break;
		case 6:
			isNotFinished = false;
			break;
		default:
			cout << "Invalid option! Please try again." << endl;
			break;
		}

	} 
	while (isNotFinished);
}

int main()
{

	if (login())
	{

		int isNotFinished = true;

		do
		{

			switch (getUserOption())
			{
			case 1:
				viewBalance();
				break;
			case 2:
				withdrawMoney();
				break;
			case 3:
				depositMoney();
				break;
			case 4:
				isNotFinished = false;
				break;
			default:
				cout << "Invalid option! Please try again." << endl;
				break;
			}

		}
		while (isNotFinished);
	}

	return 0;
}