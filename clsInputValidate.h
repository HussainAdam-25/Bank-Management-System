#pragma once
#include<iostream>
#include"clsDate.h"
#include<string>

using namespace std;


class clsInputValidate
{
private:


public:

	/////////////////////// check if the Number(int) is Between A & B

	static bool IsNumberBetween(int Number, int A, int B)
	{

		return (Number >= A && Number <= B) ? true : false;

	}

	/////////////////////// check if the Number(float) is Between A & B

	static bool IsNumberDoubleBetween(double Number, double A, double B)
	{


		return (Number >= A && Number <= B) ? true : false;

	}

	/////////////////////// check Date is Between Date1  &  Date2 

	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
	{
		if (clsDate::IsDate1BeforeDate2(Date1, Date2))
		{


			if (
				(clsDate::IsDate1BeforeDate2(Date1, Date) || clsDate::IsDate1EqualDate2(Date1, Date))
				&& (clsDate::IsDate1BeforeDate2(Date, Date2) || clsDate::IsDate1EqualDate2(Date1, Date2))

				)
			{

				return true;

			}

			else
				return false;

		}

		if (!clsDate::IsDate1BeforeDate2(Date1, Date2))
		{
			clsDate::SwapDates(Date1, Date2);


			if (clsDate::IsDate1BeforeDate2(Date1, Date2))
			{


				if (
					(clsDate::IsDate1BeforeDate2(Date1, Date) || clsDate::IsDate1EqualDate2(Date1, Date))
					&& (clsDate::IsDate1BeforeDate2(Date, Date2) || clsDate::IsDate1EqualDate2(Date1, Date2))

					)
				{

					return true;

				}

				else
					return false;

			}


		}

		return false;
	}
	/////////////////////// Read String

	static	string ReadString()
	{
		string A = "";
		getline(cin >> ws, A);
		return A;
	}

	/////////////////////// Read int Number

	static int ReadintNumber(string message = "Invalid Number,Enter again")
	{
		int number = 0;

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message << endl;
		}

		return number;

	}



	/////////////////////// Read Double Number

	static double ReadDoubleNumber(string message = "Invalid Number,Enter again")
	{
		double number = 0;

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message << endl;
		}

		return number;

	}

	/////////////////////// Read Int Number Between A & B

	static int ReadIntNumberBetween(short A, short B, string message)
	{
		int number = 0;

		number = ReadintNumber();
		while (!IsNumberBetween(number, A, B))
		{
			cout << message << endl;
			number = ReadintNumber();
		}

		return number;


	}



	/////////////////////// Read Double Number Between A & B

	static double ReadDoubleNumberBetween(short A, short B, string message)
	{
		double Number;
		Number = ReadDoubleNumber();
		while (!IsNumberDoubleBetween(Number, A, B))
		{

			cout << message << endl;
			Number = ReadDoubleNumber();
		}

		return Number;


	}

	static bool ValideDate(clsDate Date)
	{


		return	clsDate::IsValidDate(Date);

	}

};




