#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P37_SplitString {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	vector<string> SplitString(string MyString, string split) {
		string sWord;
		short pos = 0;
		vector <string> vSplitString;

		while ((pos = MyString.find(split)) != string::npos) {

			sWord = MyString.substr(0, pos);

			if (sWord != "") {
				vSplitString.push_back(sWord);
			}

			MyString.erase(0, pos + split.length());
		}

		if (MyString != "") {
			vSplitString.push_back(MyString);
		}

		return vSplitString;

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");
		vector <string> vSplitString = SplitString(MyString, "-");

		cout << "Tokens = " << vSplitString.size() << endl;
		for (string& S : vSplitString) {
			
			cout << S << endl;
		}

	}


}
