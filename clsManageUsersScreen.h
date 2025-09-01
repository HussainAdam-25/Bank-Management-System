#pragma once
#include<iostream>
#include"clsScreen.h"

#include<iomanip>
#include"clsInputValidate.h"

#include"clsUserListScreen.h"

#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"


using namespace std;
class clsManageUsersScreen : protected clsScreen
{

private:

	enum eOptionManageUsers
	{

		eListUsers = 1, eAddNewUsers = 2
		, eDeleteUsers = 3
		, eUpdateUsers = 4, eFindUsers = 5, eMainMenu = 6

	};



	///////// Go To back Main Menue Transaction
	static void _GoBackToMainMenuManageUsers()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowManageUsersScreen();
	}


	/////////// List Users Screen
	static void _ShowListUsersScreen()
	{

		//cout << "\nList Users  Client screen will be here .....\n";
		clsUserListScreen::ShowUserList();
	}

	///////////// Add New Users Screen
	static void _ShowAddNewUsersScreen()
	{

	//	cout << "\nAdd New Users Client screen will be here .....\n";
		clsAddNewUserScreen::ShowAddNewUser();
	}


	///////////// Delete Users Screen
	static void _ShowDeleteUsersScreen()
	{

		//cout << "\nDelete Users screen will be here .....\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	///////////// Update Users Screen
	static void _ShowUpdateUsersScreen()
	{

	//	cout << "\nUpdate Users screen will be here .....\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	///////////// Find Users Screen
	static void _ShowFindUsersScreen()
	{

		//cout << "\nFind Users screen will be here .....\n";
		clsFindUserScreen::ShowFindUserScreen();
	}



	///////// Performance Tranaction Screen

	static void _PerformanceManageUsersScreenOption(short NumberChoice)
{
		switch (NumberChoice)
	{
		case  eOptionManageUsers::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToMainMenuManageUsers();
			break;
		}

		case  eOptionManageUsers::eAddNewUsers:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToMainMenuManageUsers();
			break;
		}
		case  eOptionManageUsers::eDeleteUsers:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToMainMenuManageUsers();
			break;
		}

		case  eOptionManageUsers::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToMainMenuManageUsers();
			break;
		}

		case  eOptionManageUsers::eFindUsers:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToMainMenuManageUsers();
			break;
		}

		case  eOptionManageUsers::eMainMenu:
		{
			system("cls");
			break;
		}

	}
}



public:


	static void ShowManageUsersScreen()
	{



		system("cls");
		_DrawScreenHeader("Manage Users Screen");
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "           Manage Users Menue              \n";
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "\t[1] List Users.\n";
		cout << setw(30) << left << "" << "\t[2] Add New User.\n";
		cout << setw(30) << left << "" << "\t[3] Delete User.\n";
		cout << setw(30) << left << "" << "\t[4] Update User.\n";
		cout << setw(30) << left << "" << "\t[5] Find User.\n";
		cout << setw(30) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(30) << left << "" << "==============================================\n";
		

		_PerformanceManageUsersScreenOption
		(clsInputValidate::ReadIntNumberBetween(1, 6, "Enter number Between 1 to 6 ?"));

	}




};

