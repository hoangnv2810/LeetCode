#include<iostream>
#include<algorithm>
using namespace std;

int minFlipsMonoIncr(string s) {
	/*int index = s.length() - 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			index = i;
			break;
		}
	}
	int demZero = 0, demOne = 0;
	for (int i = index; i < s.length(); i++) {
		if (s[i] == '1') demOne++;
		else demZero++;
		demZero = min(demOne, demZero);
	}
	return min(demOne, demZero);*/
	int flipZero = 0, flipOne = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') flipOne++;
		else flipZero++;
		flipZero = min(flipZero, flipOne);
	}
	return flipZero;
}

int main() {
	string s;
	cin >> s;
	cout << minFlipsMonoIncr(s);
}