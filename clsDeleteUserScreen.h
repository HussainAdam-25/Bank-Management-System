#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;


class clsDeleteUserScreen : protected clsScreen
{
private :

	static 	void _PrintUser(clsUser User)
	{
		cout << "\nUser  Card   \n";
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



	static void ShowDeleteUserScreen()
	{
		////////// Print Header
		_DrawScreenHeader("Delete User Screen");

		string Username;
		char ChoiceDelete = 'n';
		
		cout << "Enter User Name :\n";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nClient With ( " << Username <<
				" ) Not Exists , Enter another User Name ?\n";

			Username = clsInputValidate::ReadString();
		}

		clsUser Deleteuser = clsUser::Find(Username);
		_PrintUser(Deleteuser);

		cout << "Do you sure you want Delete this User ? y/n ?\n\n";
		cin >> ChoiceDelete;

		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			if (Deleteuser.Delete())
			{

				cout << "\nUser Deleted Successfully :-)\n";

				Deleteuser.Print();


			}

			else


				cout << "\nError User Not Deleted :(-\n";

		}


	}

};

