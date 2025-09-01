#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsDepositeScreen.h"
#include"clsMainScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsShowTransfersLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{


private:
	enum eOptionTransactions
	{

		eDeposit = 1, eWithdraw = 2
		, eTotalBalance = 3, eTransfer=4 , eTransferLog =5, eMainMenu = 6

	};


	///////// Go To back Main Menue Transaction
	static void _GoBackToMainMenuTransaction()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowTranactionScreen();
	}


	///////////// Deposite Screen
	static void _ShowDepositeScreen()
	{

		//cout << "\nDeposit Client screen will be here .....\n";
		clsDepositeScreen::ShowDepositeScreen();
	}

	///////////// Withdraw Screen
	static void _ShowWithdrawScreen()
	{

		//cout << "\nWithdraw Client screen will be here .....\n";
		clsWithDrawScreen::ShowWithdrawScreen();
	}



	///////////// Show Transfer Screen Screen
	
		static void _ShowTransferScreen()
	{

		//cout << "\nTransfer screen will be here .....\n";
			clsTransferScreen::ShowTransferScreen();
	}

	///////////// Total Balance Screen
	static void _ShowTotalBalancesScreen()
	{

		//cout << "\nTotal Balance screen will be here .....\n";
		clsTotalBalanceScreen::ShowTotalBalance();
	}

	///////////// _Show Transfer LogScreen
	static void _ShowTransferLogScreen()
	{

		clsShowTransfersLogScreen::ShowTransferRegisterScreen();

	}

	
	///////// Performance Tranaction Screen
	static	void _PerformanceTranactionScreenOption(short NumberDoYouWant)
{

		switch (NumberDoYouWant)
		{
		case eOptionTransactions::eDeposit:
			{
				system("cls");
				_ShowDepositeScreen();
				_GoBackToMainMenuTransaction();
				break;
			}
        
		case eOptionTransactions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToMainMenuTransaction();
			break;
		}

		case eOptionTransactions::eMainMenu:
		{
			system("cls");
			
			//////////
			break;
		}

		case eOptionTransactions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToMainMenuTransaction();
			break;
		}

		case eOptionTransactions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToMainMenuTransaction();
			break;
		}

		case eOptionTransactions::eTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToMainMenuTransaction();
			break;
		}


 		}
	
}


public:
	
	
	static void ShowTranactionScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pTranactions))
		{

			return;


		}

		system("cls");
		_DrawScreenHeader("Tranaction Screen");
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "           Tranaction Menue              \n";
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "\t[1] Deposite.\n";
		cout << setw(30) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(30) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(30) << left << "" << "\t[4] Transfer.\n";
		cout << setw(30) << left << "" << "\t[5] TransferLog.\n";
		cout << setw(30) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(30) << left << "" << "==============================================\n";


		_PerformanceTranactionScreenOption
		(clsInputValidate::ReadIntNumberBetween(1, 6, "Enter number Between 1 to 6 ?"));

	}



};

