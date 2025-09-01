#pragma once

#include<iostream>
#include<string>
#include"clsScreen.h"
#include <iomanip>

#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"

#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsFindClientScreen.h"

#include"Global.h"

#include"clsShowLoginRegisterScreen.h"
#include"clsShowCurrencyExchangeScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen 
{
private :

	/////////////  enum
	enum eOptions
	{

		eClientList = 1, eAddClient = 2, eDeleteClient = 3
		, eUpdateClient = 4, eFindClient = 5, eTransactions = 6
		, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
	};


	/////////////  _GoBackToMainMenu
	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenuScreen();
	}

	/////////////  _ShowClentList
	static void _ShowAllClentScreen()
	{
		clsClientListScreen::ShowClientList();

	}

	/////////////  _AddNewClients
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClient();
		

	}

	/////////////  _DeleteClient
	static void	_ShowDeleteClientScreen()
	{
		
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	/////////////  _UpdateClient
	static void	_ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClientScreen();

	}

	/////////////  _FindClient
	static void	_ShowFindClientScreen()
	{
		//cout << "\nFind Client screen will be here .....\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	/////////////  _Transaction
	static void	_ShowTransactionMenu()
	{
		//cout << "\nTransaction Client screen will be here .....\n";
		clsTransactionScreen::ShowTranactionScreen();
	}

	/////////////  _ManageUsers
	static void	_ShowManageUsersMenu()
	{
		//cout << "\nManage Users Client screen will be here .....\n";
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	/////////////  _ShowLoginRegisterScreen
	static void	_ShowLoginRegisterScreen()
	{


		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();

	}
	
	/////////////  _Show Currency Exchange Screen
	static void _ShowCurrencyExchangeScreen()
	{

		//cout << "\n_Show Currency Exchange Screen will be here .....\n";
		clsShowCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	/////////////  _ShowEndScreen
	static void	_Logout()
	{
		//cout << "\nShow End Screen Client screen will be here .....\n";
		CurrentUser = clsUser::Find("", "");

	}

	
	/////////////  _PerformanceMainMenueOption
	static	void _PerformanceMainMenueOption(short NumberDoYouWant)
	{

		switch (NumberDoYouWant)
		{
		case  eOptions::eClientList:
		{
			system("cls");
			_ShowAllClentScreen();
			_GoBackToMainMenu();
			break;
		}

	
		case  eOptions::eAddClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		
		case  eOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
			case  eOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eOptions::eFindClient:
		{

			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		}

		case eOptions::eTransactions:
		{

			system("cls");
			_ShowTransactionMenu();
			_GoBackToMainMenu();
			break;

		}

		case eOptions::eManageUsers:
		{

			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		}
		
	
		case eOptions::eLoginRegister:
		{
			// Logout
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();

			break;

		}

		case eOptions::eCurrencyExchange:
		{
			// Currency Exchange
			system("cls");
			_ShowCurrencyExchangeScreen();

			break;

		}

		case eOptions::eLogout:
		{
			// Logout
			system("cls");
			_Logout();

			break;

		}
		    }
	}

public:


	static void ShowMainMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout <<setw(30)<< left <<""<< "==============================================\n";
		cout << setw(30)<< left << "" << "            Main Menu Screen              \n";
		cout << setw(30) << left << "" << "==============================================\n";

		cout << setw(30) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(30) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(30) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(30) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(30) << left << "" << "\t[5] Find Client.\n";
		cout << setw(30) << left << "" << "\t[6] Transactions.\n";
		cout << setw(30) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(30) << left << "" << "\t[8] Login Register.\n"; 
		cout << setw(30) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(30) << left << "" << "\t[10] Logout.\n";
		cout << setw(30) << left << "" << "==============================================\n";


		_PerformanceMainMenueOption
	(clsInputValidate::ReadIntNumberBetween(1,10,"Enter number Between 1 to 10 ?"));

	}




};



