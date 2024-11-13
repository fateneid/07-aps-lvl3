#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

namespace P48_ShowAllClients {

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
		stClientData Client;

		Client.AccountNumber = vStringWords[0];
		Client.PinCode = vStringWords[1];
		Client.Name = vStringWords[2];
		Client.Phone = vStringWords[3];
		Client.AccountBalance = stod(vStringWords[4]);

		return Client;

	}

	vector<stClientData> LoadCleintsDataFromFile(string FileName) {

		vector<stClientData> vClients;
		stClientData stClient;

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

	void PrintClientRecord(stClientData stClient) {

		cout << "| " << setw(15) << left << stClient.AccountNumber;
		cout << "| " << setw(10) << left << stClient.PinCode;
		cout << "| " << setw(40) << left << stClient.Name;
		cout << "| " << setw(12) << left << stClient.Phone;
		cout << "| " << setw(12) << left << stClient.AccountBalance;

	}

	void PrintAllClientsData(vector<stClientData> vClients) {


		cout <<"\n\t\t\t\t\tClient List  (" << vClients.size() << ")  Clients(s).";
		cout << "\n_________________________________________________________";
		cout << "___________________________________________\n\n";

		cout << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(10) << left << "Pin Code";
		cout << "| " << setw(40) << left << "Client Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(12) << left << "Balance";

		cout << "\n_________________________________________________________";
		cout<<"___________________________________________\n\n";

		for (stClientData& stClient : vClients) {

			PrintClientRecord(stClient);
			cout << endl;

		}

		cout << "\n_________________________________________________________";
		cout << "___________________________________________\n";
	}


	void Task() {

		vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);

		PrintAllClientsData(vClients);



	}


}


