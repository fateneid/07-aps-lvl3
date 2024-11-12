#pragma once

#include <iostream>
#include <string> 
using namespace std;

namespace P45_ConvertRecordToLine {

	struct stReadClientData {
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0000.0000;
	};

	stReadClientData ReadNewClient() {

		stReadClientData Client;

		cout << "Enter Account Number? ";
		getline(cin, Client.AccountNumber);
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
	
	string ConvertRecordToLineFromStruct(stReadClientData Client, string Seperator = "#//#") {

		string ClientRecord = "";
		ClientRecord += Client.AccountNumber + Seperator;
		ClientRecord += Client.PinCode + Seperator;
		ClientRecord += Client.Name + Seperator;
		ClientRecord += Client.Phone + Seperator;
		ClientRecord += to_string(Client.AccountBalance);

		return ClientRecord;

	}


	void Task() {

		cout << "Please Enter Client Data:\n\n";
		stReadClientData Client = ReadNewClient();

		cout << "\n\nClient Record for Saving is:\n";
		cout << ConvertRecordToLineFromStruct(Client) << endl;
	}


}
