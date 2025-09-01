#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsTransactionScreen.h"

using namespace std;


class clsDepositeScreen : protected clsScreen
{

private :

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
	static void ShowDepositeScreen()
	{

		double DepositAmount = 0;
		char ChoicePerformance = 'n';

		_DrawScreenHeader("Deposite Screen");


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

		cout << "\nPlease Enter Deposit amount?\n";
		cin >> DepositAmount;
		cout << "Are you sure you want perform this transaction? Y/N ?\n";
		cin >> ChoicePerformance;

		if (ChoicePerformance == 'y' || ChoicePerformance == 'Y')

		{
			Client.Deposite(DepositAmount);
			cout << "\nNew Balance Is :" << Client.AccountBalance;

		}

		else
			cout << "\nOperation Was Cancelled \n";

	}

	
	

};

