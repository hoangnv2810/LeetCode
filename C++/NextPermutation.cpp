#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void nextPermutation(vector<int>& a) {
        int i = a.size()-2;
        if(a.size() == 1) return;
        if(a.size() == 2 && a[0] == a[1]) return;
        while(a[i] > a[i+1]){
            i--;
            if(i == -1) break;
        }
        if(i == -1){
            for(int i = 0; i < a.size(); i++){
                a[i] = i+1;;
            }
            return;
        }
        int j;
        for(j = a.size()-1; j > i; j--){
            if(a[j] > a[i]) break;
        }
        swap(a[j], a[i]);
        sort(a.begin()+i+1, a.end());
        
    }
};

int main(){

}