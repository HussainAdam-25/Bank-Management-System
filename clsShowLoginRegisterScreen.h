#pragma once

#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsShowLoginRegisterScreen : protected clsScreen
{

private :

	//////// Print Register Screen 
	static void PrintRegisterScreen(clsUser::stLoginRegisterRecord RegisterRecord)
	{

		cout << "| " << setw(40) << left << RegisterRecord.DateTime;
		cout << "| " << setw(15) << left << RegisterRecord.UserName;
		cout << "| " << setw(15) << left << RegisterRecord.Password;
		cout << "| " << setw(15) << left << RegisterRecord.Pemissions;
		

	}


public :

	static void ShowLoginRegisterScreen()

	{

		if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
		{

			return;

		}
	vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord =
		clsUser::GetRgisterList();

		string Title = "Login Register List Screen";
		string SubTitle = "(" + to_string(vLoginRegisterRecord.size()) + ") Record (s)";
		_DrawScreenHeader(Title, SubTitle);


		cout << "____________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(40) << "Date/Time ";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
	
		cout << "\n\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


		for (clsUser::stLoginRegisterRecord MyRegister : vLoginRegisterRecord)
		{

			PrintRegisterScreen(MyRegister);
			cout << endl;
		}


		cout << "\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


	}


};

