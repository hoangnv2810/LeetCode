#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :val(0), left(nullptr), right(nullptr);
    TreeNode(int x) : val(x), left(nullptr), right(nullptr);
}

class Solution{
    public:
    int count = 0;
    int goodNodes(TreeNode* root){
        heper(root, root->val);
        return count;
    }
    private:
    void heper(TreeNode* node, int maxVal){
        if(!node) return;
        if(node->val >= maxVal) {
            maxVal = node->val;
            count++;
        }
        heper(node->left, maxVal);
        heper(node->right, maxVal);
    }
};

int main(){

}