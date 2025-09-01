#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;



class clsFindCurrency : protected clsScreen
{

private:
	static 	void _PrintCurrency(clsCurrency& Currency)
	{
		cout << "\nCurrency Card   \n";
		cout << "------------------------------------------\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate/(1$)  : " << Currency.Rate();

	}
	
	static void _ShowResults(clsCurrency Currency)
	{

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
		}


		else

			cout << "\nCurrency Was Not Found :-)\n";


		_PrintCurrency(Currency);

	}


	////////////////////////////////////
	static void FindCountry()
	{
		string Country = "";

		cout << "Enter Currency Country :\n";
		Country = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountry(Country);

		_ShowResults(Currency);
	}

	/////////////////////////////////////////////
	static void FindCode()
	{
		string Code = "";
		cout << "Enter Currency Code :\n";
		Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_ShowResults(Currency);

	}

	/////////////////////
public:


	static void ShowFindCurrencyScreen()
	{

		short ChoiceFind = 0;

		////////// Print Header
		_DrawScreenHeader("Find Currency Screen");

		cout << "Find By: [1] Code Or [2] Country ?\n";
		cin >> ChoiceFind;


		switch (ChoiceFind)
	{

		case 1:
		{
			FindCode();
			break;
		}

		case 2:
		{
			FindCountry();
			break;
		}



	}

	}

};

