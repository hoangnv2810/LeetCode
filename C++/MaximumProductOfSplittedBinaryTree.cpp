#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    int val;
    TreeNode left, right;
    TreeNode() {};
    TreeNode(int val) {
        this.val = val;
        this.left = NULL;
        this.right = NULL;
    }
};

class Solution{
    private:
    vector<long> allSums;
    public:
    int mod = 1e9+7;
    int maxProduct(TreeNode* root){
        long total = treeSum(root);
        long res = LONG_MIN;
        for(auto subSum : allSums){
            res = max(res, subSum*(total-subSum));
        }
        return res%mod;
    }
    long treeSum(TreeNode* subRoot){
        if(subRoot == NULL) return 0;
        long sumLeft = treeSum(subRoot->left);
        long sumRight = treeSum(subRoot->right);
        long totalSum = subRoot->val + sumLeft + sumRight;
        allSums.push_back(totalSum);
        return totalSum;
    }
};
