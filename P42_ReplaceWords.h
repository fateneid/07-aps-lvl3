#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P42_ReplaceWords {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	vector<string> SplitString(string MyString, string Split) {

		vector<string> vSplitStrig;
		string sWord;
		short pos = 0;

		while ((pos = MyString.find(Split)) != string::npos) {
			sWord = MyString.substr(0, pos);
			if (sWord != "") {
				vSplitStrig.push_back(sWord);
			}

			MyString.erase(0, pos + Split.length());
		}
		if (MyString != "") {
			vSplitStrig.push_back(MyString);
		}

		return vSplitStrig;

	}

	string ReplaceWords(string MyString, string Replace, string ReplaceWith) {

		string S = "";
		vector <string> vString = SplitString(MyString, " ");
		vector<string>::iterator iter = vString.begin();

		while (iter != vString.end()) {
			if (*iter == Replace) {
				*iter = ReplaceWith;
			}
			S += *iter + " ";
			iter++;
		}

		return S.substr(0, S.length() - 1);

	}

	string ReplaceWordUsingBuiltInFunction(string MyString, string StringToReplace, string ReplaceTo) {

		short pos = MyString.find(StringToReplace);

		while (pos != string::npos) {

			MyString = MyString.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = MyString.find(StringToReplace);

		}

		return MyString;

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");

		cout << "\nString after reversing words:\n";
		cout << ReplaceWordUsingBuiltInFunction(MyString, "Egypt", "China") << endl;


	}


}
