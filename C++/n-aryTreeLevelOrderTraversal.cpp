#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;
	Node(){}
	Node(int val) {
		this->val = val;
	}
	Node(int val, vector<Node*> children) {
		this->val;
		this->children = children;
	}
};

vector<vector<int>> levelOrder(Node* root) {
	vector<int> temp;
	vector<vector<int>> res;
	if(root == NULL) return res;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		while (n--) {
			Node* nd = q.front();
			q.pop();
			temp.push_back(nd->val);
			for (int i = 0; i < nd->children.size(); i++) {
				q.push(nd->children[i]);
			}
		}
		res.push_back(temp);
		temp.clear();
	}
	return res;
}

int main() {
	
}