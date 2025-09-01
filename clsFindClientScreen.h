#pragma once
#include<iostream>
#include"clsScreen.h"

#include"clsBankClient.h"
#include"clsInputValidate.h"


using namespace std;

class clsFindClientScreen : protected clsScreen
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



	static void ShowFindClientScreen()
	{
		char ChoiceDelete = 'n';

		if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
		{

			return;


		}

		////////// Print Header
		_DrawScreenHeader("Find Client Screen");


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

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}


		else

			cout << "\nClient Was Not Found :-)\n";


		_PrintClient(Client);

		


				

		

	}



};

