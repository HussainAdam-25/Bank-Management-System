
#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<string>

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void PrintCurrency(clsCurrency Currency)
	{

		cout << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(20) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
		
	}


public:



	static void ShowCurrencyList()

	{

	
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyList();

		string Title = "Currencies List Screen";
		string SubTitle = "(" + to_string(vCurrency.size()) + ") Currency (s)";
		_DrawScreenHeader(Title, SubTitle);

		string _Country;
		string _CurrencyCode;
		string _CurrencyName;
		float _Rate;
		cout << "____________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Country ";
		cout << "| " << left << setw(15) << "Code ";
		cout << "| " << left << setw(20) << "Name ";
		cout << "| " << left << setw(10) << "Rate/(1$) ";

		cout << "\n\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


		for (clsCurrency MyCurrency : vCurrency)
		{

			PrintCurrency(MyCurrency);
			cout << endl;
		}


		cout << "\n__________________________________________________";
		cout << "_______________________________________________________" << endl;


	}



};

