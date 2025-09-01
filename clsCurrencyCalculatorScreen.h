#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsUtility.h"
#include"clsString.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{


private :


	static 	void _PrintCurrency(clsCurrency Currency,string Title)
	{
		cout << "\n"<< Title  <<"\n";
		cout << "\nCurrency Card   \n";
		cout << "______________________________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate/(1$)  : " << Currency.Rate();
		cout << "\n______________________________________________\n";
	}

	static 	void _PrintExchangeCalculator(string Currency1Code, string Currency2Code,
		float AmountExchange,float AmountConnvertToUSD)
	{
		
		cout << AmountExchange << " " << Currency1Code << " = " << AmountConnvertToUSD << " " <<
			Currency2Code << endl;
	}


	//////////////////////////////
	static void ClaculatorCurrencyExchange(string Currency1Code,string Currency2Code, float AmountExchange)
	{
		float AmountConnvertToUSD = 0;
		float AmountConnvertFromUSDToAnotherCurrency = 0;


		clsCurrency Currency = clsCurrency::FindByCode(Currency1Code);
	   _PrintCurrency(Currency,"Convert From");

	   ///// Convert From USD To Another Currency
	   AmountConnvertToUSD= Currency.ConvertToUSD(AmountExchange);

	   _PrintExchangeCalculator(Currency1Code, "USD", AmountExchange, AmountConnvertToUSD);
	//
	   if (clsString::UpperAllLetterOfString(Currency2Code)=="USD")
	   {

		   return;
	   }


		
	clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);
	_PrintCurrency(Currency2,"To");

	///// Convert From USD To Another Currency
	AmountConnvertFromUSDToAnotherCurrency=
	Currency2.ConvertFromUSDToAnyCurrency(AmountConnvertToUSD, Currency2);

	_PrintExchangeCalculator(Currency1Code, Currency2Code, AmountExchange, AmountConnvertFromUSDToAnotherCurrency);

	}
	///////////////////////public///////////////////////

public:


	static void ShowCurrencyCalculatorScreen()
	{
		string CurrencyCodeFrom;
		string CurrencyCodeTo;
		double AmountExchange;
		char   AnotherPerform = 'n';


		do {
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			/////////////////// Currency1 Code
			cout << "Please Enter Currency1 Code :\n";
			CurrencyCodeFrom = clsInputValidate::ReadString();



			///////////////////Currency2 Code
			cout << "Please Enter Currency2 Code :\n";
			CurrencyCodeTo = clsInputValidate::ReadString();

			///////////////////Currency2 Code
			cout << "Please Enter Amount to Exchange :\n";
			AmountExchange = clsInputValidate::ReadDoubleNumber();



			ClaculatorCurrencyExchange(CurrencyCodeFrom, CurrencyCodeTo, AmountExchange);

			cout << "Do you want to perform another Calculation y/n ? ";
			cin >> AnotherPerform;

		  } while (AnotherPerform=='y' || AnotherPerform=='Y');
		



	}



};

