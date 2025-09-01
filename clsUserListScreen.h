#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;



class clsUserListScreen : protected clsScreen
{
private:

	static void PrintUser(clsUser User)
	{

		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(25) << left << User.GetFullName();
		cout << "| " << setw(10) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(15) << left << User.Permissions;

	}


public:



	static void ShowUserList()

	{
		vector <clsUser> vUsers = clsUser::GetClientList();

		string Title = "User List Screen";
		string SubTitle = "(" + to_string(vUsers.size()) + ") User (s)";
		_DrawScreenHeader(Title, SubTitle);


		cout << "____________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(15) << "Permissions";

		cout << "\n\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


		for (clsUser MyUser : vUsers)
		{

			PrintUser(MyUser);
			cout << endl;
		}


		cout << "\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


	}


};

