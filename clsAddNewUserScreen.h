#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsUtility.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

	//////////// enum Permissions
	


	static void _ReadUserData(clsUser& UserData)
	{

		cout << "Enter FirstName :\n";
		UserData.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName  :\n";
		UserData.LastName = clsInputValidate::ReadString();

		cout << "Enter Email     :\n";
		UserData.Email = clsInputValidate::ReadString();

		cout << "Enter Phone     :\n";
		UserData.Phone = clsInputValidate::ReadString();

		cout << "Enter Password     :\n";
		UserData.Password = clsInputValidate::ReadString();
	
	
		////////////////////Permissions
		cout << "Enter Permissions     :\n";
		UserData.Permissions = _ReadPermissions();


	}

	////////Read Permissions 

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

			Permission += clsUser:: enPermissions::pListClients;
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


		//////////////////////////////////////////
		cout << "Login Register  ? Y/N ?";
		cin >> choicePermission;

		if (choicePermission == 'y' || choicePermission == 'Y')
		{

			Permission += clsUser::enPermissions::pLoginRegister;
		}


		return Permission;
	}



	///////////////_Print User

	static 	void _PrintUser(clsUser  User)
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



	static void ShowAddNewUser()
	{
		_DrawScreenHeader("Add New User Screen");


		string UserName = "";
		cout << "Enter User Name :\n";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser With ( " << UserName <<
				" ) already Exists , Enter another User Name ?\n";

			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);


		cout << "\n\nAdding New User :\n\n";
		_ReadUserData(NewUser);


		clsUser::ensaveResult saveResult;
		saveResult = NewUser.save();

		switch (saveResult)
		{
		case clsUser::ensaveResult::svFaildAccountNumberExists:
		{

			cout << "\nError account was not saved because it's Empty";
			break;

		}

		case clsUser::ensaveResult::svSucceeded:
		{

			cout << "\nAccount Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;

		}


		}
	}




};

