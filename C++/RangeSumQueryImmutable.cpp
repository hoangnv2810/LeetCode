#include<bits/stdc++.h>
using namespace std;

class NumArray{
    private: 
    vector<int> data;
    public:
    NumArray(vector<int>& nums){
        data = nums;
        data.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            data[i] += data[i-1];
        }
    }

    int sumRange(int left, int right){
        return left == 0 ? data[right] : data[right]-data[left-1];
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            nums.push_back(val);
        }
        NumArray* obj = new NumArray(nums);
        obj->sumRange(0, 2);
    }
}