#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool canReorderDoubled(vector<int>& arr) {
	map<int, int> mp;
	for (auto x : arr) {
		mp[x]++;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		int temp = arr[i] / 2;
		if (arr[i] < 0 && mp[arr[i]] != 0 && temp*2 == arr[i]) {
			if (mp.find(arr[i] / 2) != mp.end() && mp[arr[i] / 2] != 0) {
				mp[arr[i] / 2]--;
				mp[arr[i]]--;
			}
			else {
				return false;
			}
		}
		else if(arr[i] >= 0 && mp[arr[i]] != 0){
			if (mp.find(arr[i] * 2) != mp.end() && mp[arr[i] * 2] != 0) {
				mp[arr[i] * 2]--;
				mp[arr[i]]--;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	vector<int> v = { 5, 2 };
	cout << canReorderDoubled(v);
}