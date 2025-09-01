#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;


class clsFindUserScreen : protected clsScreen
{
private:

	static 	void _PrintUser(clsUser  User)
	{
		cout << "\nUser Card   \n";
		cout << "------------------------------------------\n";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFullName       : " << User.GetFullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nUserName       : " << User.UserName;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions;
		cout << "\n------------------------------------------\n";
	}


public:



	static void ShowFindUserScreen()
	{
		char ChoiceDelete = 'n';

		////////// Print Header
		_DrawScreenHeader("Find User Screen");

		string UserName;
		cout << "Please Enter User Name :";
		cin >> UserName;


		while (!clsUser::IsUserExist(UserName))
		{

			cout << "Account Number is not found, choose another one : ";
			cin >> UserName;

		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}


		else

			cout << "\nUser Was Not Found :-)\n";


		_PrintUser(User);



	}


};

