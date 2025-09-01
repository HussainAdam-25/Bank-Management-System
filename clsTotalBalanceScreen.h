#pragma once
#include<iostream>
#include <iomanip>
#include<fstream>
#include<vector>
#include<string>

#include"clsUtility.h"
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;


class clsTotalBalanceScreen : protected clsScreen
{

private :

	static void _PrintTotalBalance(clsBankClient Clientdata)
	{

		cout << setw(25) << left << "" << "| " << setw(15) << left << Clientdata.AccountNumber;
		cout << "| " << setw(40) << left << Clientdata.GetFullName();
		cout << "| " << setw(12) << left << Clientdata.AccountBalance;

	}

public :

	static void ShowTotalBalance()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "Balance List Screen";
		string SubTitle = "(" + to_string(vClients.size()) + ") Cleint (s)";
		_DrawScreenHeader(Title, SubTitle);


		double TotalBalances = 0;

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		for (clsBankClient Client : vClients)
		{

			_PrintTotalBalance(Client);
			cout << endl;
			TotalBalances = TotalBalances + Client.AccountBalance;

		}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";

	}



};

