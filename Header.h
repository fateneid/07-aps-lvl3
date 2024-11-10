#include <iostream>
#include <vector>
using namespace std;


void FillSGroup(int r, int l, vector <int>& S) {
	for (int i = r; i <= l; i++) {
		S.push_back(i);
	}
}

int ProccesCounter(vector <int> S, int k) {
	int Counter1 = 0, Counter2 = 0;
	for (auto i = S.begin(); i < S.end(); i++) {
		Counter1 = 0;
		for (auto j = S.begin(); j < S.end(); j++) {
			if (*j % *i == 0) {
				Counter1++;
				if (Counter1 >= k) {
					Counter2++;
					S.erase(i);
					break;

				}

			}
		}
	}
	return Counter2;

}
	
	
int main() {
	int r, l, k;
	cin >> r >> l >> k;
	vector <int> S;
	FillSGroup(r, l, S);
		
	ProccesCounter(S, k);


}

