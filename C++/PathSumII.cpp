#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

vector<vector<int>> res;
vector<int> path;
vector<vector<int>> PathSumII(TreeNode* root, int sum) {
	findPaths(root, sum);
	return res;
}

void findPaths(TreeNode* root, int sum) {
	if (root == NULL) return;
	path.push_back(root->data);
	if (root->left == NULL && root->right == NULL && sum == root->data) {
		res.push_back(path);
	}
	findPaths(root->left, sum - root->data);
	findPaths(root->right, sum - root->data);
	path.pop_back();

}

