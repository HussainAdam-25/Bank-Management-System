#pragma once
#include<iostream>
#include"clsPerson.h"
//#include"clsString.h"
#include<fstream>
#include<vector>
#include<string>
#include"clsDate.h"

using namespace std;


const string ClientdataFileName = "Clients.txt";
class clsBankClient : public clsPerson
{
private:

	enum enumMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };

	enumMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkForDelete = false;

	///////////Convert Line to Client Object

	static clsBankClient _ConvertLinetoClientObject(string line, string Delim = "#//#")
	{
		vector<string> vClinteData;


		vClinteData = SplitString(line, Delim);


		return clsBankClient(enumMode::UpdateMode, vClinteData[0], vClinteData[1], vClinteData[2],
			vClinteData[3], vClinteData[4], vClinteData[5], stof(vClinteData[6]));
	}


	static clsBankClient _GetEmptyClientObject()
	{


		return clsBankClient(enumMode::EmptyMode, "", "", "", "", "", "", 0);


	}

	///////////Convert Object To Line

	static string _ConvertRecordToLine(clsBankClient Client)
	{
		string Delim = "#//#";
		string line = "";
		line += Client.FirstName + Delim;
		line += Client.LastName + Delim;
		line += Client.Email + Delim;
		line += Client.Phone + Delim;
		line += Client.AccountNumber + Delim;
		line += Client.PinCode + Delim;
		line += to_string(Client.AccountBalance) + Delim;

		return line;
	}
	////// LOad Data From File 

	static vector <clsBankClient> _LoadClientDataFromFile()
	{

		fstream MyData;

		vector <clsBankClient> Clientdata;

		string line = "";

		MyData.open("Clients.txt", ios::in);

		if (MyData.is_open())
		{
			while (getline(MyData, line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(line);
				Clientdata.push_back(Client);

			}

			MyData.close();

		}

		return Clientdata;
	}


	////// save data To File 
	static void  _SaveClientsDataToFile(vector <clsBankClient> vClientdata)
	{
		fstream MyFile;
		string DataFileNew = "";

		MyFile.open("Clients.txt", ios::out);


		if (MyFile.is_open())
		{


			for (clsBankClient C : vClientdata)
			{
				if (C.MarkForDelete == false)
				{
					DataFileNew = _ConvertRecordToLine(C);
					MyFile << DataFileNew << endl;

				}


			}


			MyFile.close();
		}



	}
	////////// Add new Client

	void _AddNew()
	{

		_AddDataLineToFile(ClientdataFileName, _ConvertRecordToLine(*this));

	}

	void _AddDataLineToFile(string ClientdataFileName, string stDataLine)
	{
		fstream MyFile;
		MyFile.open(ClientdataFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			
			MyFile << stDataLine<<endl;

			MyFile.close();

		}

	}


	////////// _Update 

	void _Update()
	{
		vector <clsBankClient> _vClients;     // ÌÕ ÊÌ ⁄·Ï Ã„Ì⁄ «· Clients
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}

		}

		_SaveClientsDataToFile(_vClients);
	}


	string _PrepareTransferLogRecord(double Amount, clsBankClient& DestinatoinClient, string UserName,string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateAndLocalTime() + Seperator;
		LoginRecord += AccountNumber + Seperator;
		LoginRecord += DestinatoinClient.AccountNumber + Seperator;
		LoginRecord += to_string(Amount) + Seperator;
		LoginRecord += to_string(AccountBalance) + Seperator;
		LoginRecord += to_string(DestinatoinClient.AccountBalance) + Seperator;
		LoginRecord += UserName + Seperator;
		return LoginRecord;
	}

	struct stTransferRecord;

	////////// Convet Transfer To Object
	static	stTransferRecord _ConvertTransferLinetoObject(string line, string Delim = "#//#")
	{
		
			vector<string> vRegisterData;
     	stTransferRecord TransferRegisterRecord;
		
		
		vRegisterData = SplitString(line, Delim);

		TransferRegisterRecord.DateTime = vRegisterData[0];
		TransferRegisterRecord.So_AccNumber = vRegisterData[1];
		TransferRegisterRecord .De_AccNumber= vRegisterData[2];
		TransferRegisterRecord.Amount = stod(vRegisterData[3]);
		TransferRegisterRecord.So_Balance = stod(vRegisterData[4]);
		TransferRegisterRecord.De_Balance = stod(vRegisterData[5]);
		TransferRegisterRecord.UserName = vRegisterData[6];

		return TransferRegisterRecord;
	}


	/////////////_Register Transfer 
	void  _RegisterTransfer(double Amount, clsBankClient& DestinatoinClient, string UserName)
	{
		fstream MyFile;
		string DataFileNew = "";

		MyFile.open("TransferRegister.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{

			while (true)
			{

		DataFileNew = _PrepareTransferLogRecord(Amount, DestinatoinClient, UserName);
		MyFile << DataFileNew << endl;


				break;

			}


			MyFile.close();
		}



	}

public:

	clsBankClient(enumMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	///////////struct For Transfer

	struct stTransferRecord
	{
		string DateTime;
		string So_AccNumber;
		string De_AccNumber;
		double Amount;
		double So_Balance;
		double De_Balance;
		string UserName;

	};

	//Properity Set
	void SetAccountNumber(string AccountNumber)
	{

		_AccountNumber = AccountNumber;

	}
	//Properity Get
	string GetAccountNumber()
	{

		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber;


	//Properity Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;

	}
	//Properity Get
	string GetPinCode()
	{

		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;


	//Properity Set
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;

	}
	//Properity Get
	float GetAccountBalance()
	{

		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;



	////// IsEmpty Mode

	bool IsEmpty()
	{

		return (_Mode == enumMode::EmptyMode);
	}
	////// Print
	void Print()
	{
		cout << "\nClient Card   \n";
		cout << "------------------------------------------\n";
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFullName       : " << GetFullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccountNumber  : " << _AccountNumber;
		cout << "\nPinCode        : " << _PinCode;
		cout << "\nAcoountBalance : " << _AccountBalance;
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


	///// find Client By AccountNumber Only

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClientdata;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;

				}

			}
			MyFile.close();
		}


		return _GetEmptyClientObject();
	}

	///// find Client By AccountNumber & PinCode
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClientdata;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;

				}

			}
			MyFile.close();
		}


		return _GetEmptyClientObject();
	}


	//////////////////////////////
	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client5 = clsBankClient::Find(AccountNumber);
		return (!Client5.IsEmpty());
	}


	//////////////////////////////

	enum ensaveResult {
		svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2

	};


	//////////////////////////////
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

	static	clsBankClient GetAddNewClientObject(string AccountNumber)
	{


		return clsBankClient(enumMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);

	}

	/////////// Delete Client

	bool Delete()
	{

		vector <clsBankClient> _vClients;     // ÌÕ ÊÌ ⁄·Ï Ã„Ì⁄ «· Clients
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C.MarkForDelete = true;
				break;
			}

		}

		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	////////////// Get Client List For Print it
	static vector <clsBankClient> GetClientList()
	{

		
		return _LoadClientDataFromFile();
		 
	}

	void Deposite(double Amount)
	{

		_AccountBalance += Amount;
		save();
	}


	void WithDraw(double Amount)
	{

		_AccountBalance -= Amount;
		save();
	}


	bool Transfer(double Amount , clsBankClient &DestinatoinClient,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;

		}
		WithDraw(Amount);
		DestinatoinClient.Deposite(Amount);
		_RegisterTransfer(Amount, DestinatoinClient, UserName);
		return true;
	}

	////////////// Get Transfer List For Print it
	static vector <stTransferRecord> GetTransferList()
	{

		stTransferRecord TransferRecord;

		fstream MyData;

		vector <stTransferRecord> vTransferRegister;

		string line = "";

		MyData.open("TransferRegister.txt", ios::in);

		if (MyData.is_open())
		{
			while (getline(MyData, line))
			{

				TransferRecord = _ConvertTransferLinetoObject(line);
				vTransferRegister.push_back(TransferRecord);

			}

			MyData.close();

		}

		return vTransferRegister;

	}



};


