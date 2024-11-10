#pragma once

#include <iostream>
#include <vector>
using namespace std;

namespace Header1 {

	int ProccesCounter(int r, int l, int k) {
		int Max = 0;

		for (int i =  r; i <= l; i++) {

			if (k == 1)
				return (l - r + 1);

			int MultipleCount = (l / i) - ((r - 1) / i);

			if(MultipleCount>=k){
				Max++;

			}
		}
		return Max;
		
	}


	void Task() {

		int n;
		cin >> n;

		while (n > 0) {

			int r, l, k;
			cin >> r >> l >> k;

			cout << ProccesCounter(r, l, k);
			cout << endl;

			n--;
		}
		

	}
}
