#pragma once

#include<iostream>

using namespace std;


class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;


public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}

	//Properity Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;

	}
	//Properity Get
	string GetFirstName()
	{

		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	//Properity Set
	void SetLastName(string LastName)
	{
		_LastName = LastName;

	}


	//Properity Get

	string GetLastName()
	{
		return _LastName;

	}

	//Properity Get
	string GetFullName()
	{
		return _FirstName + " " + _LastName;

	}

	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	//Properity Set

	void SetEmail(string Email)
	{

		_Email = Email;
	}

	//Properity Get

	string GetEmail()
	{
		return _Email;

	}

	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	//Properity Set
	void SetPhone(string Phone)
	{

		_Phone = Phone;
	}


	//Properity Get

	string GetPhone()
	{
		return _Phone;

	}

	__declspec(property(get = GetPhone, put = SetPhone))string Phone;
};

