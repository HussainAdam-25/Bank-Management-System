#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsUtility.h"

using namespace std;


class clsUpdateUserScreen : protected clsScreen
{
	static void  _ReadUsertData(clsUser & User)
	{
	
		cout << "\nUpdate User Info :\n";
		cout << "Enter FirstName :\n";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName  :\n";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email     :\n";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone     :\n";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password     :\n";
		User.Password = clsInputValidate::ReadString();
		////////////////////Permissions
		
		cout << "Enter Permissions     :\n";
		User.Permissions = _ReadPermissions();

	}

	///////////_ReadPermissions
	static int _ReadPermissions()
	{

		short Permission = 0;
		char choicePermission = 'y';


		//////////////////////////////////////////

		cout << "Do you want to give Full access ? Y/N";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			return -1;
		}
		//////////////////////////////////////////
		cout << "\nDo you want to give access to :\n";

		cout << "Show client list ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pListClients;
		}

		//////////////////////////////////////////
		cout << "Add new client  ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pAddNewClient;
		}

		//////////////////////////////////////////
		cout << "Delete client  ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pDeleteClient;
		}
		//////////////////////////////////////////
		cout << "Update client  ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pUpdateClients;
		}

		//////////////////////////////////////////

		cout << "Find client  ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pFindClient;
		}

		//////////////////////////////////////////

		cout << "Tranactions ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pTranactions;
		}

		//////////////////////////////////////////

		cout << "Manage Users ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pManageUsers;
		}

		return Permission;
	}


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



	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

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

		_ReadUsertData(User);

		clsUser::ensaveResult saveResult;


		char ChoiceUpdate = 'n';

		cout << "Do you sure you want Update this User ? y/n ?\n\n";
		cin >> ChoiceUpdate;

		if (ChoiceUpdate == 'Y' || ChoiceUpdate == 'y')
		{
			saveResult = User.save();
			switch (saveResult)
			{

			case clsUser::ensaveResult::svSucceeded:
			{

				cout << "\nAccount Updated Successfully :-)\n";
				_PrintUser(User);
				break;

			}


			case clsUser::ensaveResult::svFaildEmptyObject:
			{

				cout << "\nError account was not saved because it's Empty";
				break;

			}
			}

		}
		else
			cout << "Not updated...\n";



	}





};

