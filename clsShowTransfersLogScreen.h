#pragma once
#include<iostream>
#include"clsScreen.h"


using namespace std;


class clsShowTransfersLogScreen : protected clsScreen
{

private:

	//////// Print Register Screen 
	static void PrintTransferScreen(clsBankClient::stTransferRecord TansferRecord)
	{

		cout << "| " << setw(30) << left << TansferRecord.DateTime;
		cout << "| " << setw(10) << left << TansferRecord.So_AccNumber;
		cout << "| " << setw(10) << left << TansferRecord.De_AccNumber;
		cout << "| " << setw(10) << left << TansferRecord.Amount;
		cout << "| " << setw(10) << left << TansferRecord.So_Balance;
		cout << "| " << setw(10) << left << TansferRecord.De_Balance;
		cout << "| " << setw(10) << left << TansferRecord.UserName;


	}


public:

	static void ShowTransferRegisterScreen()

	{

		/*if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
		{

			return;

		}*/
		vector <clsBankClient::stTransferRecord> vTransferRegisterRecord =
			clsBankClient::GetTransferList();

		string Title = "Transfer Log List Screen";
		string SubTitle = "(" + to_string(vTransferRegisterRecord.size()) + ") Record (s)";
		_DrawScreenHeader(Title, SubTitle);


		cout << "____________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Date/Time ";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";


		cout << "\n\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


		for (clsBankClient::stTransferRecord  MyRegister : vTransferRegisterRecord)
		{

			PrintTransferScreen(MyRegister);
			cout << endl;
		}


		cout << "\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


	}



};

