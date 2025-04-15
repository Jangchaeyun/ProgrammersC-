#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node
{
	int data;
	int x, y;
	Node* left;
	Node* right;

	Node(int _data, int _x, int _y) : data(_data), x(_x), y(_y)
	{
		left = NULL;
		right = NULL;
	}
};

bool compare(Node a, Node b)
{
	if (a.y == b.y) return a.x < b.x;
	else return a.y > b.y;
}

void setParent(Node* parent, Node* node)
{
	if (parent->x > node->x)
	{
		if (parent->left == NULL)
		{
			parent->left = node;
			return;
		}
		setParent(parent->left, node);
	}
	else
	{
		if (parent->right == NULL)
		{
			parent->right = node;
			return;
		}
		setParent(parent->right, node);
	}
}

void preorder(Node* root, vector<int>& pre)
{
	pre.push_back(root->data);
	if (root->left != NULL) preorder(root->left, pre);
	if (root->right != NULL) preorder(root->right, pre);
}

void postorder(Node* root, vector<int>& post)
{
	if (root->left != NULL) postorder(root->left, post);
	if (root->right != NULL) postorder(root->right, post);
	post.push_back(root->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	vector<Node> tree;
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		tree.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	}

	sort(tree.begin(), tree.end(), compare);

	Node* root = &tree[0];
	for (int i = 1; i < tree.size(); i++)
	{
		setParent(root, &tree[i]);
	}

	vector<int> answer1;
	preorder(root, answer1);

	vector<int> answer2;
	postorder(root, answer2);

	answer.push_back(answer1);
	answer.push_back(answer2);

	return answer;
}