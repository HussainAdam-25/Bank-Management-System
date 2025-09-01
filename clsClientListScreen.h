#pragma once
#include<iomanip>
#include<fstream>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsBankClient.h"
#include"clsUser.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private :

	static void PrintRecord(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(25) << left << Client.GetFullName();
		cout << "| " << setw(10) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(15) << left << Client.AccountBalance;

	}


public :

	

	static void ShowClientList()

	{

		if (!CheckAccessRight(clsUser::enPermissions::pListClients))
		{

			return;


		}
		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "Cleint List Screen";
		string SubTitle = "("+ to_string(vClients.size())+ ") Cleint (s)";
		_DrawScreenHeader(Title, SubTitle);


		cout << "____________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin code";
		cout << "| " << left << setw(15) << "Balance";

		cout << "\n\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


		for (clsBankClient MyClient : vClients)
		{

			PrintRecord(MyClient);
			cout << endl;
		}


		cout << "\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


	}




	


};


