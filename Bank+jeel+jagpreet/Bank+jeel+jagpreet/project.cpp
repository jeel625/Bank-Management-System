#include <iostream>
#include <string>
#include <iomanip>
#include<cstdlib>
#include <limits>


using namespace std;


string firstName[100];
string lastName[100];
long accountNo[100];
bool firstButton = false;
double copy_balance[100];
double accountBalance[100];
int accountCounter = 0;


long randAccountNo();
void display(long no);
void addBankAccount();
void removeAccount(long acno);
double getUserDouble();
long getUserLong();
int getUserInt();
string getUserString();
void withdrawl(long no);
void deposit(long no);
void sortingData(long acno[], int arraysize);
void swapData(long arrayTemp[], int index1, int index2);
void displayAverage();
void totalValueOfAccount();


int main()
{
	cout << "	****************                   ****************" << endl;
	cout << "	****************WELCOME TO THE BANK****************" << endl;
	cout << "	****************                   ****************" << endl;
	int switchVariable; // for input from user
	bool exit=true;// to repeat this loop if user don't want to exit
	cout << fixed << setprecision(2);

	for (int i = 0; i < 100; i++)
	{
		accountNo[i] = 0;
	}

	// Menu ....
	do
	{
		cout << endl << endl;
		cout << "	1.	Add a bank account." << endl;
		cout << "	2.	Remove a bank account. (by account number)" << endl;
		cout << "	3.	Display the information of a particular client's account. (by account number)" << endl;
		cout << "	4.	Apply a deposit to a particular account. (by account number)" << endl;
		cout << "	5.	Apply a withdrawal from a particular account. (by account number)" << endl;
		cout << "	6.	Sort and display the list of clients according to their balance or their account number" << endl;
		cout << "	7.	Display the average balance value of all accounts at the bank." << endl;
		cout << "	8.	Display the total balance value of all the accounts of the bank." << endl;
		cout << "	9.	Exit the application." << endl;

		cout <<endl<<endl<< "	Please choose any option = ";
		switchVariable = getUserInt();

		switch (switchVariable)
		{
		case 1:
		{
			cout << "\n***************Thanks for choosing our service***************\n" << endl;
			cout << "\n***************ADD A BANK ACCOUNT***************\n" << endl;
			firstButton = true;
			addBankAccount();
			break;
		}
		case 2:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n***************Remove a bank account. (by account number)****************\n" << endl;
				long acc_no;
				cout << "Please Enter account number :";
				acc_no = getUserLong();
				removeAccount(acc_no);
			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 3:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n***************Display the information of a particular client's account. (by account number)***************" << endl;
				long acc_no;
				cout << "Please Enter account number :";
				acc_no = getUserLong();
				display(acc_no);

			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 4:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n***************Apply a deposit to a particular account. (by account number)***************" << endl;
				long acc_no;
				cout << "Please Enter account number :";
				acc_no = getUserLong();
				deposit(acc_no);
			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 5:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n****************Apply a withdrawal from a particular account. (by account number)*************** " << endl;
				long acc_no;
				cout << "Please Enter account number :";
				acc_no = getUserLong();
				withdrawl(acc_no);
			}
			else
				cout << "**********Please First add bank account**********" << endl;

			break;
		}
		case 6:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n ***************Sort and display the list of clients according to their balance or their account number***************" << endl;

				sortingData(accountNo, accountCounter);

				for (int i = 0;i < accountCounter ;i++)
				{
							cout << endl << endl << "**********Client's information**********" << endl;
							cout << "	Accout number is = " << accountNo[i] << endl;
							cout << "	First name is : " << firstName[i] << endl;
							cout << "	Last name is : " << lastName[i] << endl;
							cout << "	balace is : " << accountBalance[i]<<endl;
							cout << "****************************************" << endl;
				}
			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 7:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n*********************Display the average balance value of all accounts at the bank.************************* " << endl;
				displayAverage();
			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 8:
		{
			if (accountCounter == 0)
				firstButton = false;
			if (firstButton)
			{
				cout << "\n*********************Display the total balance value of all the accounts of the bank.********************           " << endl;
				totalValueOfAccount();
			}
			else
				cout << "**********Please First add bank account**********" << endl;
			break;
		}
		case 9:
		{
			exit = false;
			break;
		}
		default:
		{
			cout << "\nInvalid Input......" << endl;
			break;
		}
		}
	} while (exit);
	system("pause");
	return 0;
}
double getUserDouble()
{
	double temp;
	cin >> temp;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input try again.....";
		cin >> temp;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return temp;
}
long getUserLong()
{
	long temp;
	cin >> temp;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input try again.....";
		cin >> temp;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return temp;
}
int getUserInt()
{
	int temp;
	cin >> temp;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input try again.....";
		cin >> temp;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return temp;
}
string getUserString()
{
	string userString;
	bool hasSpace = false;
	do
	{
		getline(cin, userString);
		hasSpace = false;
		for (int i = 0;i < userString.length();i++)
		{
			if (userString[i] == ' ')
			{
				cout << "Invalid input. Please write only single word : ";
				hasSpace = true;
				break;
			}
		}
	} while (hasSpace);
	return userString;
}

long randAccountNo()
{
	long acno;
	int seed = time(0);
	srand(seed);

	 acno=100000+(rand() % (999999 - 100000));

	 return acno;
}

void addBankAccount()
{
	bool temp = false;
	int i = accountCounter;

	do
	{
		cout << endl << endl;
		accountNo[i] = randAccountNo();
		cout << "Your Account number is: " << accountNo[i] << endl;

		cout << "Please enter your  first Name :";
		firstName[i] = getUserString();

		cout << "Please enter your  Last Name :";
		lastName[i] = getUserString();
		cout << "Please enter amount that you want to add in your new account : $";
		accountBalance[i] = getUserDouble();
		cout<< endl << endl;
		copy_balance[i] = accountBalance[i];//just copied the original balance into another variable for sorting data and will use later..


		i++;
		accountCounter++;

		cout << "Do you want to continue to add account? press 1 for yes or 0 for no.."<<endl;
		temp = getUserInt();
	} while (temp);
}
void removeAccount(long acno)
{
	bool temp = true;
	for (int i = 0;i < accountCounter;i++)
	{
		if (accountNo[i] == acno)
		{
			cout << "First Name = " << firstName[i] << endl;
			cout << "Last Name = " <<lastName[i] << endl;
			cout << "Balance = $" << accountBalance[i] << endl;
			cout << accountNo[i] << " Account has been removed from the bank" << endl<<endl;

			for (int j = i;j < accountCounter;j++)
			{
				accountNo[j] = accountNo[j + 1];
				accountBalance[j] = accountBalance[j + 1];
				copy_balance[j] = copy_balance[j + 1];
				firstName[j] = firstName[j + 1];
				lastName[j] = lastName[j + 1];
				temp = false;
			}
		}
	}
	accountCounter--;
	if (temp)
		cout << "No match found.Please Try again";
}
void display(long acno)
{
	bool temp = true;
	cout << endl << endl;
	for (int i = 0;i < 100;i++)
	{
		if (accountNo[i] == acno)
		{
			cout << endl << endl << "**********Client's information**********" << endl;
			cout << "Accout number is = " << accountNo[i] << endl;
			cout << "First name is : " << firstName[i] << endl;
			cout << "Last name is : " << lastName[i] << endl;
			cout << "balace is : $" << accountBalance[i];
			temp = false;
			break;
		}
	}
	if (temp)
		cout << "No match found.Please Try again";
}
void deposit(long no)
{
	double money;
	bool temp=true;

	for (int i = 0;i < 100;i++)
	{
		if (accountNo[i] == no)
		{
			cout << "Please enter any amount for deposit =";
			money = getUserDouble();
			accountBalance[i] += money;
			copy_balance[i] += money;
			cout <<firstName[i]<<" "<<lastName[i]<<"'s account successfully credited with  $ " << money << endl;
			cout << " Total Balance is =$ " << accountBalance[i];
			temp = false;
			break;
		}
	}
	if (temp)
		cout << "No match found.Please Try again";

}
void withdrawl(long no)
{
	double money=0;
	bool temp = true;

	for (int i = 0;i < 100;i++)
	{
		if (accountNo[i] == no)
		{
			if (money > accountBalance[i])
				cout << "insufficient Balance . Please tray again" << endl;
			else
			{
				cout << "Please enter any amount for withdrawl =";
				money = getUserDouble();
				accountBalance[i] -= money;
				copy_balance[i]-= money;
				cout << firstName[i] << " " << lastName[i] << " withdraw  $ " <<money <<" from the bank account "<< endl;
				cout << "Remaining balance is = $" << accountBalance[i]<<endl<<endl;
				temp = false;
				break;
			}
		}
	}
	if(temp)
		cout << "No match found.Please Try again";
}
void sortingData(long acno[], int arraysize)
{
	for (int i = 0;i < arraysize - 1;i++)
	{
		for (int j = 0;j < (arraysize - 1) - i;j++)
		{
			if (acno[j] > acno[j + 1])
				swapData(acno, j, j + 1);
		}
	}
}
void swapData(long arrayTemp[], int index1, int index2)
{
	double temp;
	temp = arrayTemp[index1];
	arrayTemp[index1] = arrayTemp[index2];
	arrayTemp[index2] = temp;
}
void  displayAverage()
{
	long totalAverage = 0;

	for (int i = 0;i <= accountCounter;i++)
		totalAverage += accountBalance[i];

	cout << fixed << setprecision(2);
	cout << "Number of account holder is = " << accountCounter<<endl;
	cout << "Total Average of the Bank is = $" << (totalAverage / (double)accountCounter) << endl;

}
void totalValueOfAccount()
{
	long totalAmount = 0;

	for (int i = 0;i <= accountCounter;i++)
		totalAmount += accountBalance[i];

	cout << fixed << setprecision(2);
	cout << "Number of account holder is = " << accountCounter << endl;
	cout << "Total Balance of the Bank is = $" << totalAmount << endl;
}
void displayInformation()
{
	for (int i = 0;i < accountCounter;i++)
	{
		cout << endl << endl << "**********Client's information**********" << endl;
		cout << "Accout number is = " << accountNo[i] << endl;
		cout << "First name is : " << firstName[i] << endl;
		cout << "Last name is : " << lastName[i] << endl;
		cout << "Balace is : $" << accountBalance[i]<<endl;
	}
}
