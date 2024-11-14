#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

namespace P50_DeleteClientByAccountNumber {

	const string ClientsFileName = "ClientsFile.txt";

	struct stClientData {
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0.0;
		bool MarkForDelete = false;
	};

	vector<string> SplitString(string MyString, string Split) {

		vector<string> vStringWords;
		string sWord = "";
		short pos = 0;

		while ((pos = MyString.find(Split)) != std::string::npos) {
			sWord = MyString.substr(0, pos);
			if (sWord != "") {
				vStringWords.push_back(sWord);
			}

			MyString.erase(0, pos + Split.length());
		}

		if (MyString != "") {
			vStringWords.push_back(MyString);
		}

		return vStringWords;

	}

	stClientData ConvertLineDataToRecord(string DataLine, string Seperator = "#//#") {

		vector<string> vStringWords = SplitString(DataLine, Seperator);
		stClientData stClient;

		stClient.AccountNumber = vStringWords[0];
		stClient.PinCode = vStringWords[1];
		stClient.Name = vStringWords[2];
		stClient.Phone = vStringWords[3];
		stClient.AccountBalance = stod(vStringWords[4]);

		return stClient;

	}

	vector<stClientData> LoadCleintsDataFromFile(string FileName) {

		stClientData stClient;
		vector<stClientData> vClients;

		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				stClient = ConvertLineDataToRecord(Line);
				vClients.push_back(stClient);

			}

			MyFile.close();

		}

		return vClients;

	}

	bool FindClientByAccountNumber(vector<stClientData> vClients, string AccountNumber, stClientData& Client) {

		for (stClientData& stClient : vClients) {

			if (stClient.AccountNumber == AccountNumber) {

				Client = stClient;
				return true;

			}

		}

		return false;

	}

	void PrintClientCard(stClientData stClient) {

		cout << "\nThe following are the client details:\n";

		cout << "\nAccount Number: " << stClient.AccountNumber;
		cout << "\nPin Code      : " << stClient.PinCode;
		cout << "\nName          : " << stClient.Name;
		cout << "\nPhone         : " << stClient.Phone;
		cout << "\nAccount Balance: " << stClient.AccountBalance << endl;

	}

	string ConvertRecordToLine(stClientData stClient, string Seperator = "#//#") {

		string DataLine = "";

		DataLine += stClient.AccountNumber + Seperator;
		DataLine += stClient.PinCode + Seperator;
		DataLine += stClient.Name + Seperator;
		DataLine += stClient.Phone + Seperator;
		DataLine += to_string(stClient.AccountBalance);

		return DataLine;

	}

	void SaveDataFromVectorToFile(vector<stClientData> vClients, string FileName) {

		fstream MyFile;

		MyFile.open(FileName, ios::out);

		if (MyFile.is_open()) {

			string DataLine;

			for (stClientData stClient : vClients) {

				if (stClient.MarkForDelete == false) {

					DataLine = ConvertRecordToLine(stClient);
					MyFile << DataLine << endl; 
				}

			}

			MyFile.close();

		}

	}

	bool MarkClientForDeleteByAccountNumber(vector<stClientData>& vClients, string AccountNumber) {

		for (stClientData& stClient : vClients) {
			if (stClient.AccountNumber == AccountNumber) {
				stClient.MarkForDelete = true;
				return true;
			}
		}

		return false;

	}

	void DeleteClientByAccountNumber(vector<stClientData>& vClients, string AccountNumber, string FileName) {

		char ConfirmeDeletion;

		cout << "\nAre you sure you want to delete this client? y/n ? ";
		cin >> ConfirmeDeletion;

		if (toupper(ConfirmeDeletion) == 'Y') {

			MarkClientForDeleteByAccountNumber(vClients, AccountNumber);
			SaveDataFromVectorToFile(vClients, FileName);

			vClients = LoadCleintsDataFromFile(FileName);

			cout << "\n\nClient Deleted Successfully.\n";


		}

	}

	void Task() {

		vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
		stClientData Client;
		string AccountNumber;

		cout << "Please enter AccountNumber? ";
		cin >> AccountNumber;

		if (FindClientByAccountNumber(vClients, AccountNumber, Client)) {

			PrintClientCard(Client);
			DeleteClientByAccountNumber(vClients, AccountNumber, ClientsFileName);
			
		}
		else {

			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";

		}

	}

}