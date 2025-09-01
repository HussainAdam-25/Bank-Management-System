#pragma once
#include<iostream>
#include"clsScreen.h"


using namespace std;


class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientData(clsBankClient& ClientData)
	{

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

    static 	void _PrintClient(clsBankClient  Client)
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

	

	static void ShowAddNewClient()
	{  

		if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
		{

			return;


		}

		_DrawScreenHeader("Add New Client Screen");


		string AccountNumber = "";
		cout << "Enter Account Number :\n";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With ( " << AccountNumber <<
				" ) already Exists , Enter another Account number ?\n";

			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		cout << "Add New Client :\n";
		_ReadClientData(NewClient);


		clsBankClient::ensaveResult saveResult;
		saveResult = NewClient.save();

		switch (saveResult)
		{
		case clsBankClient::ensaveResult::svFaildAccountNumberExists:
		{

			cout << "\nError account was not saved because it's Empty";
			break;

		}

		case clsBankClient::ensaveResult::svSucceeded:
		{

			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;

		}


		}
	}


};

