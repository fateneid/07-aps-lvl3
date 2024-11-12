#pragma once

#include <iostream>
#include <string> 
#include <vector>
using namespace std;

namespace P46_ConvertLineDataToRecord {

	struct stReadClientData {
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0000.0000;
	};

	vector<string> SplitString(string MyString, string Split) {

		vector<string> vStringWords;
		string sWord = "";
		short pos = 0;

		while ((pos = MyString.find(Split)) != string::npos) {
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

	stReadClientData ConvertLineDataToRecord(string LineRecord, string Seperator = "#//#") {

		vector<string> vStringWords = SplitString(LineRecord, Seperator);

		stReadClientData Client;

		Client.AccountNumber = vStringWords[0];
		Client.PinCode = vStringWords[1];
		Client.Name = vStringWords[2];
		Client.Phone = vStringWords[3];
		Client.AccountBalance = stod(vStringWords[4]);

		return Client;

	}

	void PrintClientRecord(stReadClientData Client) {

		cout << "\nThe following is the extracted client record:\n";

		cout << "\nAccount Number  : " << Client.AccountNumber;
		cout << "\nPin Code        : " << Client.PinCode;
		cout << "\nName            : " << Client.Name;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAccount Balance : " << Client.AccountBalance << endl;

	}


	void Task() {

		string LineRecord = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

		stReadClientData Client = ConvertLineDataToRecord(LineRecord);

		cout << "Line Record is:\n" << LineRecord << endl;

		PrintClientRecord(Client);


	}


}