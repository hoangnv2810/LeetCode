#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
	stack<char> st;
	if (s.size() == 1) return false;
	for (auto x : s) {
		if ((x == ')' || x == '}' || x == ']') && !st.empty()) {
			if (st.top() == '(' && x == ')' || st.top() == '{' && x == '}' || st.top() == '[' && x == ']') {
				st.pop();
			}
			else {
				return false;
			}
		}
		else {
			st.push(x);
		}
	}
	return st.empty();
}

int main() {
	cout << isValid("){");
}