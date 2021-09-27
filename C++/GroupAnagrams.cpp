#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>;
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& s) {
	vector<vector<string>> res;
	vector<string> tmp;
	int check = true;
	for (int i = 0; i < s.size(); i++) {
		string temp = s[i];
		if (temp.length() != 0) check = false;
		sort(temp.begin(), temp.end());
		tmp.push_back(temp);
	}
	if (check) {
		res.push_back(s);
		return res;
	}

	vector<string> st;
	vector<bool> vs(s.size(), false);
	for (int i = 0; i < s.size(); i++) {
		string temp;
		if (!vs[i]) {
			st.push_back(s[i]);
			temp = s[i];
			sort(temp.begin(), temp.end());
		}
		else continue;
		for (int j = i + 1; j < s.size(); j++) {
			if (temp == tmp[j]) {
				st.push_back(s[j]);
				vs[j] = true;
			}
		}
		sort(st.begin(), st.end());
		if (st.size() != 0)
			res.push_back(st);
		st.clear();
	}
	return res;
}

int main() {
	vector<string> s = { "","","", "ab"};
	vector<vector<string>> res = groupAnagrams(s);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}