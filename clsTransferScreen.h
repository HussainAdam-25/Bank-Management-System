#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;




class clsTransferScreen : protected clsScreen
{

private :


	static void _PrintClient(clsBankClient Client)
	{

	
		cout << "\nClient Card   : \n\n";
		cout << "______________________________\n\n";
		cout << "\nFull Name   : " << Client.GetFullName();
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n\n______________________________\n\n";
	}




public :
	
	static void ShowTransferScreen()
	{
		string AccountNumberTransferFrom;
		string AccountNumberTransferTo;
		double TransferAmount = 0;
		char ChoiceDelete = 'n';


		_DrawScreenHeader("Transfer Screen Screen");

		cout << "Please Enter Account Number To transfer From : ";
		AccountNumberTransferFrom = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumberTransferFrom))
		{
			cout << "\nClient With ( " << AccountNumberTransferFrom <<
				" ) Not Exists , Enter another Account number ?\n";

			AccountNumberTransferFrom = clsInputValidate::ReadString();
		}


		clsBankClient SourceClient = clsBankClient::Find(AccountNumberTransferFrom);
		_PrintClient(SourceClient);

	////////////////////////////////////////////////////////////////
		cout << "Please Enter Account Number To transfer To : ";
		AccountNumberTransferTo = clsInputValidate::ReadString();


		while (!clsBankClient::IsClientExist(AccountNumberTransferTo))
		{
			cout << "\nClient With ( " << AccountNumberTransferTo <<
				" ) Not Exists , Enter another Account number ?\n";

			AccountNumberTransferTo = clsInputValidate::ReadString();
		}


		clsBankClient DestinationClient = clsBankClient::Find(AccountNumberTransferTo);
		_PrintClient(DestinationClient);

		cout << "Enter Transfer Amount ? ";
		cin >> TransferAmount;

	

		cout << "Are you sure you want Perform this Operation ? y/n ?\n\n";
		cin >> ChoiceDelete;

		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{
			if (SourceClient.Transfer(TransferAmount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\n\nTransfer done Successfully   ";
				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);

			}

			else
			{
				cout << "\n\nTransfer Failed ";
			}
				
		}



   }










};

