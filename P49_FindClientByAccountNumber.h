#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

namespace P49_FindClientByAccountNumber {

	const string ClientsFileName = "ClientsFile.txt";

	struct stClientData {
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0.0;
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

	bool FindClientByAccountNumber(string AccountNumber, stClientData& Client) {

		vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
		
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

	void Task() {

		string AccountNumber;
		stClientData Client;

		cout << "Please enter AccountNumber? ";
		cin >> AccountNumber;

		if (FindClientByAccountNumber(AccountNumber, Client)) {

			PrintClientCard(Client);

		}
		else {
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";

		}


	}


}
