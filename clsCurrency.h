#pragma once

#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"

using namespace std;

class clsCurrency
{

private :

	enum enMode{EmptyMode=0 , UpdateMode=1  };
	enMode  _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	////////////////SplitString
	static	vector <string> _SplitString(string S1, string Delim)
	{
		vector <string> vString;

		string sWord = " ";
		short pos = 0;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{

			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")

		{
			vString.push_back(S1);
		}

		return vString;

	}



	//////////_Get Empty Currency Object
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);

	}

	////////////////_ConvertUsersLinetoObject
	static	clsCurrency _ConvertCurrencyLinetoObject(string line, string Delim = "#//#")
	{
		vector <string> vCurrencyData;


		vCurrencyData = _SplitString(line, Delim);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0],
			vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));

	}


	///////////Convert Object To Line

	static string _ConvertObjectCurrencyToLine(clsCurrency Currency)
	{
		string Delim = "#//#";
		string line = "";
		line += Currency.Country() + Delim;
		line += Currency.CurrencyCode() + Delim;
		line += Currency.CurrencyName() + Delim;
		line += to_string(Currency.Rate()) + Delim;

		return line;

	}


	//////////////_LoadUserDataFromFile

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{

		fstream MyData;

		vector <clsCurrency> vCurrency;

		string line = "";

		MyData.open("Currencies.txt", ios::in);

		if (MyData.is_open())
		{
			while (getline(MyData, line))
			{

				clsCurrency Currency = _ConvertCurrencyLinetoObject(line);
				vCurrency.push_back(Currency);

			}

			MyData.close();

		}

		return vCurrency;
	}


	////// save data To File 
	static void  _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	{
		fstream MyFile;
		string DataNew = "";

		MyFile.open("Currencies.txt", ios::out);


		if (MyFile.is_open())
		{


			for (clsCurrency C : vCurrency)
			{
				
				DataNew = _ConvertObjectCurrencyToLine(C);
				MyFile << DataNew << endl;

			}


			MyFile.close();
		}

	}

	//////////////// _Update 

	void _Update()
	{
		vector <clsCurrency> _vCurrency;
		_vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : _vCurrency)
		{
			if (C.CurrencyCode()== CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrency);
	}



public:

	clsCurrency(enMode Mode , string Country , string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{

		return _Mode == enMode::EmptyMode;
	}


	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{

		_Rate = Rate;
		_Update();
	}

	float Rate()
	{

		return _Rate;

	}


	///////Find By Code

	static clsCurrency FindByCode(string CurrencyCode)
	{
		
		fstream MyFile;

		CurrencyCode=clsString::UpperAllLetterOfString(CurrencyCode);

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrency Currency = _ConvertCurrencyLinetoObject(line);
				if (Currency.CurrencyCode() == CurrencyCode )
				{
					MyFile.close();
					return Currency;

				}

			}
			MyFile.close();


		}


		return _GetEmptyCurrencyObject();
	}


	///////Find By Country
	static clsCurrency FindByCountry(string Country)
	{
	
		fstream MyFile;

		Country = clsString::UpperAllLetterOfString(Country);

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrency Currency = _ConvertCurrencyLinetoObject(line);
				if (clsString::UpperAllLetterOfString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;

				}

			}
			MyFile.close();
		}


		 return _GetEmptyCurrencyObject();
	}

	//////////////Is Currency Exist
	static bool IsCurrencyExistByCode(string CurrencyCountry)
	{

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);
		return (!Currency.IsEmpty());
	}


	//////////////Is Currency Exist
	static bool IsCurrencyExistByCountry(string CurrencyCode)
	{

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}


	////////////// Get Client List For Print it
	static vector <clsCurrency> GetCurrencyList()
	{


		return _LoadCurrencyDataFromFile();

	}

	float ConvertToUSD(float Amount)
	{

		return (Amount / Rate());
	}


	float ConvertFromUSDToAnyCurrency(float Amount, clsCurrency Currency2)
	{

		return (Amount * Currency2.Rate());
	}

};

