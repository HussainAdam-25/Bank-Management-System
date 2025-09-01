#pragma once
#include<iostream>
#include"clsScreen.h"


using namespace std;



class clsUpdateClientScreen : protected clsScreen
{

private :
	
	static void  _ReadClientData(clsBankClient& ClientData)
{
	vector <string> vClient;
	cout << "\nUpdate Client Info :\n";
	cout << "Enter FirstName :\n";
	ClientData.FirstName = clsInputValidate::ReadString();

	cout << "Enter LastName  :\n";
	ClientData.LastName = clsInputValidate::ReadString();

	cout << "Enter Email     :\n";
	ClientData.Email = clsInputValidate::ReadString();

	cout << "Enter Phone     :\n";
	ClientData.Phone = clsInputValidate::ReadString();

	cout << "Enter PinCode     :\n";
	ClientData.PinCode = clsInputValidate::ReadString();

	cout << "Enter Account Balance     :\n";
	ClientData.AccountBalance = clsInputValidate::ReadDoubleNumber();



}


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

	

	static void UpdateClientScreen()
	{ 
		if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients))
		{

			return;


		}


		_DrawScreenHeader("Update Client Screen");
 
		string AccountNumber;
		cout << "Please Enter client account number :";
		cin >> AccountNumber;


		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "Account Number is not found, choose another one : ";
			cin >> AccountNumber;

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	         _PrintClient(Client1);

		_ReadClientData(Client1);

		clsBankClient::ensaveResult saveResult;
	

		char ChoiceDelete = 'n';

		cout << "Do you sure you want Update this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;

		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{
			saveResult = Client1.save();
			switch (saveResult)
			{

			case clsBankClient::ensaveResult::svSucceeded:
			{

				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(Client1);
				break;

			}


			case clsBankClient::ensaveResult::svFaildEmptyObject:
			{

				cout << "\nError account was not saved because it's Empty";
				break;

			}
			}

		}
		else
			cout << "Not update...\n";

		

}


	


};

