#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"

#include"clsUser.h"
#include"Global.h"
#include"clsUtility.h"

using namespace std;

class clsShowLoginScreen : protected clsScreen
{
private:

	
	static bool _Login()
	{
		string Username = "";
		string Password = "";

		bool LoginFailed = false;
		short FailedLoginCount = 3;

		
		do {


			if (LoginFailed)
			{
				FailedLoginCount--;
				cout <<"\nInValid username/Password !\n";
				cout << "You have "<< FailedLoginCount<<" Trials to login\n ";
			}
			if (LoginFailed && FailedLoginCount ==0)
			{
				
				cout << "\n\nYou Are locked After 3 failed Trials \n\n";
				return false;
			}

			cout << "Enter username ?";
			Username = clsInputValidate::ReadString();

			cout << "Enter Password ?";
			Password = clsInputValidate::ReadString();

			

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenuScreen();
	}

public:

	static bool	ShowLoginScreen()
	{

		_DrawScreenHeader("Show Login Screen");
		return _Login();

	}
	

};

