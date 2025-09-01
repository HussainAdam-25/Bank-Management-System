
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"


using namespace std;




class clsShowCurrencyExchangeScreen : protected clsScreen
{


private:
	enum eOptionCurrencyExchange
	{

		eListCurrencies = 1, eFindCurrency = 2
		, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5

	};


	///////// Go To back Main Menue List Currencies
	static void _GoBackToMainMenuCurrencyExchange()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrencyExchangeScreen();
	}


	///////////// List Currencies Screen
	static void _ShowListCurrenciesScreen()
	{

	//	cout << "\nList Currencies screen will be here .....\n";
		clsCurrenciesListScreen::ShowCurrencyList();
	}



	///////////// _Show Find Currency Screen
	static void _ShowFindCurrencyScreen()
	{

		//cout << "\n Find Currency screen will be here .....\n";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	///////////// _Show Update Rate Screen
	static void _ShowUpdateRateScreen()
	{

		//cout << "\n Update Rate screen will be here .....\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}

	///////////// _Show Currency Calculator Screen
	static void _ShowCurrencyCalculatorScreen()
	{

	//	cout << "\nCurrency Calculator screen will be here .....\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	

	///////// Performance List Currencies Screen
	static	void _PerformanceCurrencyExchangeScreenOption(short NumberDoYouWant)
	{

		switch (NumberDoYouWant)
		{
		         case eOptionCurrencyExchange::eListCurrencies:
		           {
		             	system("cls");
			           _ShowListCurrenciesScreen();
			           _GoBackToMainMenuCurrencyExchange();
			            break;
		           }

				  case eOptionCurrencyExchange::eFindCurrency:
				  {
					  system("cls");
					  _ShowFindCurrencyScreen();
					  _GoBackToMainMenuCurrencyExchange();
					  break;
				  }

				  case eOptionCurrencyExchange::eUpdateRate:
				  {
					  system("cls");
					  _ShowUpdateRateScreen();
					  _GoBackToMainMenuCurrencyExchange();
					  break;
				  }

				  case eOptionCurrencyExchange::eCurrencyCalculator:
				  {
					  system("cls");
					  _ShowCurrencyCalculatorScreen();
					  _GoBackToMainMenuCurrencyExchange();
					  break;
				  }

				  case eOptionCurrencyExchange::eMainMenu:
				  {
					 
					  system("cls");
				
				  }

		}
	}

public:


	static void ShowCurrencyExchangeScreen()
	{

		/*if (!CheckAccessRight(clsUser::enPermissions::pTranactions))
		{

			return;


		}*/

		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "           Currency Exchange Menue              \n";
		cout << setw(30) << left << "" << "==============================================\n";
		cout << setw(30) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(30) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(30) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(30) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(30) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(30) << left << "" << "==============================================\n";


		_PerformanceCurrencyExchangeScreenOption
		(clsInputValidate::ReadIntNumberBetween(1, 5, "Enter number Between 1 to 5 ?"));

	}



};

