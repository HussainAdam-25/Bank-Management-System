#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsPerson.h"
#include"Global.h"
#include<fstream>
#include<string>
#include<vector>
#include"clsDate.h"
#include"clsUtility.h"

using namespace std;


class clsUser : public clsPerson
{

private:
	enum enumMode { EmptyMode = 0, UpdateMode = 1,
		            AddNewMode = 2, DeleteMode = 3 };


	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkUser = false;
	enumMode _Mode;


	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateAndLocalTime() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password, 3) + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}


	struct stLoginRegisterRecord;
	////////// Convet Register User To Object
	static	stLoginRegisterRecord _ConvertRegisterLinetoObject(string line, string Delim = "#//#")
	{ 
		vector<string> vRegisterData;
	stLoginRegisterRecord LoginRegisterRecord;

	
	vRegisterData = SplitString(line, Delim);

	LoginRegisterRecord.DateTime = vRegisterData[0];
	LoginRegisterRecord.UserName= vRegisterData[1];
	LoginRegisterRecord.Password = clsUtil::DyscryptText(vRegisterData[2], 3) ;
	LoginRegisterRecord.Pemissions = stoi(vRegisterData[3]);

	return LoginRegisterRecord;
	}


	////////// Convet Line User To Object
	static	clsUser _ConvertUsersLinetoObject(string line, string Delim = "#//#")
	{
		vector<string> vUserData;
		
		
		vUserData = SplitString(line, Delim);

	return clsUser(enumMode::UpdateMode,vUserData[0], vUserData[1], vUserData[2], vUserData[3],
		vUserData[4], clsUtil::DyscryptText( vUserData[5],3), stoi(vUserData[6])
		);

	}
	
	//////////_Get Empty User Object
	static clsUser _GetEmptyUserObject()
	{


		return clsUser(enumMode::EmptyMode, "", "", "", "", "", "", 0);


	}


	///////////Convert Object To Line

	static string _ConvertObjectToLine(clsUser User)
	{
		string Delim = "#//#";
		string line = "";
		line += User.FirstName + Delim;
		line += User.LastName + Delim;
		line += User.Email + Delim;
		line += User.Phone + Delim;
		line += User.UserName + Delim;
		line += clsUtil::EncryptText(User.Password,3) + Delim;
		line += to_string(User.Permissions) + Delim;
		
		return line;
	}


	////// LOad Data From File 
	
	static vector <clsUser> _LoadUserDataFromFile()
	{
		
		fstream MyData;

		vector <clsUser> Userdata;

		string line = "";

		MyData.open("Users.txt", ios::in);

		if (MyData.is_open())
		{
			while (getline(MyData, line))
			{

				clsUser Client = _ConvertUsersLinetoObject(line);
				Userdata.push_back(Client);

			}

			MyData.close();

		}

		return Userdata;
	}


	 ////// save data To File 
	 static void  _SaveUsersDataToFile(vector <clsUser> vClientdata)
	 {
		 fstream MyFile;
		 string DataFileNew = "";

		 MyFile.open("Users.txt", ios::out);


		 if (MyFile.is_open())
		 {


			 for (clsUser C : vClientdata)
			 {
				 if (C._MarkUser == false)
				 {
					 DataFileNew = _ConvertObjectToLine(C);
					 MyFile << DataFileNew << endl;

				 }


			 }


			 MyFile.close();
		 }

 }

	 ////////// Add new User

	  void _AddNew()
	 {

		 _AddDataLineToFile("Users.txt", _ConvertObjectToLine(*this));

	 }
	 
	/**/
	 static void _AddDataLineToFile(string UserFileName, string stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open(UserFileName, ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();

		 }

	 }

	 ////////// _Update 

	  void _Update()
	 {
		 vector <clsUser> _vUsers;     // ÌÕ ÊÌ ⁄·Ï Ã„Ì⁄ «· Clients
		 _vUsers = _LoadUserDataFromFile();

		 for (clsUser& C : _vUsers)
		 {
			 if (C._UserName == _UserName)
			 {
				 C = *this;
				 break;
			 }

		 }

		 _SaveUsersDataToFile(_vUsers);
	 }


	/////////////////////////////// Public ////////////////////////////////////////
public:
	 // Constructor 
	clsUser(enumMode Mode, string FirstName, string LastName, string Email
		, string Phone,string UserName,string Password,int Permissions) :
		clsPerson(FirstName,LastName,Email,Phone)
	{

		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_Mode = Mode;

	}


 	struct stLoginRegisterRecord
	{ 
		string DateTime;
		string UserName;
		string Password;
		int Pemissions;


	};

	

	static enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
		pLoginRegister=128
	};
	////////////// Set & Get For UserName

	//Properity Set
	void SetUserName(string UserName)
	{

		_UserName = UserName;

	}
	//Properity Get
	string GetUserName()
	{

		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	////////////// Set & Get For Password

	//Properity Set
	void SetPassword(string Password)
	{

		_Password = Password;

	}
	//Properity Get
	string GetPassword()
	{

		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	////////////// Set & Get For Permissions

	//Properity Set
	void SetPermissions(int Permissions)
	{

		_Permissions = Permissions;

	}
	//Properity Get
	int GetPermissions()
	{

		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	/////////////Register Login Date And Local Time 
	 void  RegisterLogin()
	{
		fstream MyFile;
		string DataFileNew = "";

		MyFile.open("LoginRegister.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{

			while (true)
			{

				DataFileNew = _PrepareLogInRecord();
				MyFile << DataFileNew << endl;


				break;

			}


			MyFile.close();
		}



	}
	 

	////// IsEmpty Mode

	bool IsEmpty()
	{

		return (_Mode == enumMode::EmptyMode);
	}

	////// Print
	void Print()
	{
		cout << "\nUser Card   \n";
		cout << "------------------------------------------\n";
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFullName       : " << GetFullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nUserName       : " << _UserName;
		cout << "\nPassword       : " << _Password;
		cout << "\nPermissions    : " << _Permissions;
		cout << "\n------------------------------------------\n";
	}

	////// Split String 

	static	vector <string> SplitString(string S1, string Delim)
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

	///// find User By UserName Only
	
	static clsUser Find(string UserName)
	{
		vector <clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertUsersLinetoObject(line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;

				}

			}
			MyFile.close();
		}


		return _GetEmptyUserObject();
	}

	///// find Client By AccountNumber & PinCode
	static clsUser Find(string UserName, string Password)
	{
		vector <clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertUsersLinetoObject(line);
				if (User.UserName == UserName  &&  User.Password == Password)
				{
					MyFile.close();
					return User;

				}

			}
			MyFile.close();
		}


		return _GetEmptyUserObject();
	}


	//////////////Is User Exist
	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	static bool IsUserExist(string UserName, string Password)
	{

		clsUser User = clsUser::Find(UserName, Password);
		return (User.IsEmpty());
	}

	/////////////////enum save Result

	enum ensaveResult {
		svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2

	                  };

	ensaveResult save()
	{
		switch (_Mode)
		{

		case  enumMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return ensaveResult::svFaildEmptyObject;
			}

		}


		case  enumMode::UpdateMode:
		{
			_Update();
			return ensaveResult::svSucceeded;

		}

		case  enumMode::AddNewMode:
		{
			_AddNew();
			return ensaveResult::svSucceeded;
		}


		}

	}

	///////////GetAddNewClientObject
	static	clsUser GetAddNewUserObject(string UserName)
	{


		return clsUser(enumMode::AddNewMode, "", "", "", "", UserName, "", 0);

	}

	/////////// Delete Client

	bool Delete()
	{

		vector <clsUser> _vUsers;     // ÌÕ ÊÌ ⁄·Ï Ã„Ì⁄ «· Clients
		_vUsers = _LoadUserDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C.UserName == _UserName)
			{
				C._MarkUser = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	////////////// Get Client List For Print it
	static vector <clsUser> GetClientList()
	{


		return _LoadUserDataFromFile();

	}


	////////////// Get Rgister List For Print it
	static vector <stLoginRegisterRecord> GetRgisterList()
	{
		stLoginRegisterRecord LoginRegisterRecord;

			fstream MyData;

			vector <stLoginRegisterRecord> vLoginRegisterRecord;

			string line = "";

			MyData.open("LoginRegister.txt", ios::in);

			if (MyData.is_open())
			{
				while (getline(MyData, line))
				{

					LoginRegisterRecord = _ConvertRegisterLinetoObject(line);
					vLoginRegisterRecord.push_back(LoginRegisterRecord);

				}

				MyData.close();

			}

			return vLoginRegisterRecord;
		
}


	//////////////

	 bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this-> Permissions == enPermissions::eAll)

			return true;

		if ((Permissions & this-> Permissions) == Permissions)

			return true;
		else 
			return false;


	}






};

