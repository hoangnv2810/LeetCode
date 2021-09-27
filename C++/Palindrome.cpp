#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string& s, int start, int end) {
	while (start < end) {
		if (s[start++] != s[end--]) return false;
	}
	return true;
}
void palindromePartition(vector<vector<string>>& res, vector<string> &temp, int start, string& s) {
	if (start >= s.length()) res.push_back(temp);
	for (int end = start; end < s.length(); end++) {
		if (isPalindrome(s, start, end)) {
			temp.push_back(s.substr(start, end - start + 1));
			palindromePartition(res, temp, end + 1, s);
			temp.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> temp;
	palindromePartition(res, temp, 0, s);
	return res;
}

int main() {
	vector<vector<string>> res = partition("aab");
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}