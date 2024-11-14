#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

namespace P51_UpdateClientByAccountNumber {

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

	vector<stClientData> LoadClientsDataFromFile(string FileName) {

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

	void UpdateClient(stClientData& stClient) {

		cout << "Enter PinCode? ";
		getline(cin >> ws, stClient.PinCode);
		cout << "Enter Name? ";
		getline(cin, stClient.Name);
		cout << "Enter Phone? ";
		getline(cin, stClient.Phone);
		cout << "Enter AccountBalance? ";
		cin >> stClient.AccountBalance;

	}

	void UpdateClientByAccountNumber(vector<stClientData>& vClients, string AccountNumber, string FileName) {

		char ConfirmeUpdate;

		cout << "\nAre you sure you want to update this client? y/n ? ";
		cin >> ConfirmeUpdate;

		if (toupper(ConfirmeUpdate) == 'Y') {

			for (stClientData& stClient : vClients) {

				if (stClient.AccountNumber == AccountNumber) {

					cout << "\n\n";
					UpdateClient(stClient);
					break;

				}

			}

			SaveDataFromVectorToFile(vClients, FileName);
			cout << "\n\nClient Updated Successfully.\n";
			return;

		}

	}

	void Task() {

		vector<stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
		stClientData Client;
		string AccountNumber;

		cout << "Please enter AccountNumber? ";
		cin >> AccountNumber;

		if (FindClientByAccountNumber(vClients, AccountNumber, Client)) {

			PrintClientCard(Client);
			UpdateClientByAccountNumber(vClients, AccountNumber, ClientsFileName);

		}
		else {

			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";

		}

	}

}


