#include<iostream>
#include<string>
using namespace std;
typedef struct NODE
{
	string data;
	NODE* left;
	NODE* right;
};
typedef struct NODE* TREE;

void khoiTao(TREE &root)
{
	root = NULL;
}

NODE* newNode(string data)
{
	NODE* node = new NODE;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
bool checkNode(NODE *node)
{
	return node->left == NULL && node->right == NULL;
}

float tinhToan(string data, double x, double y)
{
	
	if (data == "+"){
		return x + y;
	}                                 
	if (data == "-") {
		return x - y;
	}
	if (data == "*") {
		return x * y; 
	}
	if (data == "/") {
		return x / y;
	}
	return 0;
}
float LNR(TREE root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (checkNode(root))
	{
		return stod(root->data);
	}
	float a = LNR(root->left);
	cout << "node a: " << a << endl;
	float b = LNR(root->right);
	cout << "node b: " << b << endl;
	return tinhToan(root->data, a, b);
}
int main()
{
	TREE root ;
	khoiTao(root);
	root = newNode("-");

	root->left = newNode("/");
	root->right = newNode("+");

	root->left->left = newNode("*");
	root->left->right = newNode("+");
	root->right->left = newNode("*");
	root->right->right = newNode("6");

	root->left->left->left = newNode("+");
	root->left->left->right = newNode("3");
	root->left->right->left = newNode("-");
	root->left->right->right = newNode("2");
	root->right->left->left = newNode("3");
	root->right->left->right = newNode("-");

	root->left->left->left->left = newNode("-");
	root->left->left->left->right = newNode("1");
	root->left->right->left->left = newNode("9");
	root->left->right->left->right = newNode("+");
	root->right->left->right->left = newNode("7");
	root->right->left->right->right = newNode("4");

	root->left->left->left->left->left = newNode("8");
	root->left->left->left->left->right = newNode("1");
	root->left->right->left->right->left = newNode("2");
	root->left->right->left->right->right = newNode("6");


	cout << "ket qua: " << LNR(root) << endl;
	return 0;
}