#pragma once
#include<iostream>
#include"clsScreen.h"


using namespace std;

class clsWithDrawScreen : protected clsScreen
{

private:
	static 	void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card   \n";
		cout << "------------------------------------------\n";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFullName       : " << Client.GetFullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccountNumber  : " << Client.AccountNumber;
		cout << "\nPinCode        : " << Client.PinCode;
		cout << "\nAcoountBalance : " << Client.AccountBalance;
		cout << "\n------------------------------------------\n";
	}

public:
	static void ShowWithdrawScreen()
	{

		double WithDraw = 0;
		char ChoicePerformance = 'n';

		_DrawScreenHeader("Withdraw Screen");


		string AccountNumber = "";
		cout << "Enter Account Number :\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With ( " << AccountNumber <<
				" ) Not Exists , Enter another Account number ?\n";

			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease Enter Withdraw amount?\n";
		cin >> WithDraw;

		cout << "Are you sure you want perform this transaction? Y/N ?\n";
		cin >> ChoicePerformance;


		if (ChoicePerformance == 'y' || ChoicePerformance == 'Y')

		{
			if (WithDraw> Client.AccountBalance)
			{
				cout << "Cannot Withdraw ,Insuffecient Balance\n";
				cout << "Amount Withdraw is :"<< WithDraw<<endl;
				cout << "Account Balance is :" << Client.AccountBalance << endl;
			}

			else
			{ 
				Client.WithDraw(WithDraw);
				cout << "\nNew Balance Is :" << Client.AccountBalance;
			}
			

		}

		else
			cout << "\nOperation Was Cancelled \n";

	}




};

