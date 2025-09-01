#pragma once

#include<iostream>

#include<fstream>
#include<vector>
#include<string>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen :  protected clsScreen
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

public :


	static void ShowDeleteClientScreen()
	{
		char ChoiceDelete = 'n';


		if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
		{

			return;


		}
		////////// Print Header
		_DrawScreenHeader("Delete Client Screen");


		string AccountNumber = "";
		cout << "Enter Account Number :\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With ( " << AccountNumber <<
				" ) Not Exists , Enter another Account number ?\n";

			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
		_PrintClient(DeleteClient);

		cout << "Do you sure you want Delete this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;

		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			if (DeleteClient.Delete())
			{

				cout << "\nClient Deleted Successfully :-)\n";

				DeleteClient.Print();


			}

			else


				cout << "\nError Client Not Deleted :(-\n";

		}

	}

};

