
#pragma once
#include<iostream>
#include"clsScreen.h"

#include"clsCurrency.h"
#include"clsInputValidate.h"


using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:


	static 	void _PrintCurrency(clsCurrency& Currency)
	{
		cout << "\nCurrency Card   \n";
		cout << "______________________________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate/(1$)  : " << Currency.Rate();
		cout << "\n______________________________________________\n";
	}

public:



	static void ShowUpdateCurrencyScreen()
	{
		string CurrencyCode = "";
		char ChoiceDelete = 'n';
		float Rate;

		_DrawScreenHeader("Update Currency Screen");


		cout << "Please Enter Currency Code :\n";
		CurrencyCode = clsInputValidate::ReadString();
	
		/*while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}*/


		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "Do you sure you want Update this Currency ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{
			cout << "\n\nUpdate Currency Rate :\n";

			cout << "______________________________\n";
			cout << "Enter New Rate :";
			cin >> Rate;
			Currency.UpdateRate(Rate);
			cout << "\n\nCurrency Rate updated Successfuly\n";
			_PrintCurrency(Currency);

		}



		else
			cout << "Not update...\n";

	}

};

