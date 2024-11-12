#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace P47_AddClientsToFile {

	const string ClientsFileName = "ClientsFile.txt";

	struct stReadClientData {
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0.0;
	};

	stReadClientData AddingNewClient() {

		stReadClientData Client;

		cout << "Enter Account Number? ";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, Client.AccountNumber);
		cout << "Enter PinCode? ";
		getline(cin, Client.PinCode);
		cout << "Enter Name? ";
		getline(cin, Client.Name);
		cout << "Enter Phone? ";
		getline(cin, Client.Phone);
		cout << "Enter AccountBalance? ";
		cin >> Client.AccountBalance;

		return Client;

	}

	string ConvertRecordToLine(stReadClientData Client, string Seperator = "#//#") {

		string DatatLine = "";

		DatatLine += Client.AccountNumber + Seperator;
		DatatLine += Client.PinCode + Seperator;
		DatatLine += Client.Name + Seperator;
		DatatLine += Client.Phone + Seperator;
		DatatLine += to_string(Client.AccountBalance);

		return DatatLine;

	}

	void AddDataLineToFile(string FileName, string DatatLine) {

		fstream MyFile;

		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << DatatLine << endl;
		}

		MyFile.close();


	}

	void AddNewClient() {

		stReadClientData Client = AddingNewClient();
		string DatatLine = ConvertRecordToLine(Client);
		AddDataLineToFile(ClientsFileName, DatatLine);

	}

	void AddClients() {

		char AddMore = 'Y';

		while (toupper(AddMore) == 'Y') {

			system("cls");
			cout << "Adding New Clients:\n\n";
			AddNewClient();
			cout << "\nClient Added Successfully, do you want to add more clients? ";
			cin >> AddMore;

		}

	}


	void Task() {


		AddClients();


	}

}
