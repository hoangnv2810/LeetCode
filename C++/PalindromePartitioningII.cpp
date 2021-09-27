#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//Approad 1
//bool isPalindrome(string& s, int start, int end) {
//	while (start < end) {
//		if (s[start++] != s[end--]) return false;
//	}
//	return true;
//}
//
//int minPalindromePartion(string s, int i, int j) {
//	if (i >= j || isPalindrome(s, i, j)) return 0;
//	int res = INT_MAX, count;
//	for (int k = i; k < j; k++) {
//		count = minPalindromePartion(s, i, k) + minPalindromePartion(s, k + 1, j) + 1;
//		res = min(res, count);
//	}
//	return res;
//}
//
//int minCut(string s) {
//	return minPalindromePartion(s, 0, s.length() - 1);
//}

//int minCut(string s) {
//	int n = s.length();
//	int C[n][n];
//	bool P[n][n];
//	for (int i = 0; i < n; i++) {
//		P[i][i] = true;
//		C[i][i] = 0;
// 	}
//
//	for (int L = 2; L <= n; L++) {
//		for (int i = 0; i < n - L + 1; i++) {
//			int j = i + L - 1;
//			if (L == 2 && s[i] == s[j]) {
//				P[i][j] = true;
//			}
//			else {
//				P[i][j] = (s[i] == s[j]) && P[i + 1][j - 1];
//			}
//
//			if (P[i][j]) C[i][j] = 0;
//			else {
//				C[i][j] = INT_MAX;
//				for (int k = i; k <= j - 1; k++) {
//					C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
//				}
//			}
//		}
//	}
//	return C[0][n - 1];
//}


int minCut(string s) {
	int cut[3];
	bool palindrome[3][3];
	memset(palindrome, false, sizeof(palindrome));
	for (int j = 0; j < s.length(); j++) {
		int minCut = j;
		for (int i = 0; i <= j; i++) {
			if (s[i] == s[j] && (j - i <= 2 || palindrome[i + 1][j - 1])) {
				palindrome[i][j] = true;
				minCut = min(minCut, i == 0 ? 0 : (cut[i-1]+1));
			}
		}
		cut[j] = minCut;
	}
	return cut[s.length()-1];
}

int main() {
	cout << minCut("aab");
}