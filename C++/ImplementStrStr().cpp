#include<iostream>
#include<algorithm>
using namespace std;

int strStr(string a, string b) {
	int m = a.size(), n = b.size();
	for (int i = 0; i <= m - n; i++) {
		int j;
		for (j = 0; j < b.size(); j++) {
			if (a[i + j] != b[j]) break;
		}
		if (j == n) return i;
	}
	return -1;
}

int main() {

}