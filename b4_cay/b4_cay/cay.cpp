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

float tinhToan(string data, float x, float y)
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
float NLR(TREE root)
{
	if (root == NULL){
		return 0;
	}
	if (checkNode(root)){
		return stod(root->data);
	}
	float a = NLR(root->left);
	float b = NLR(root->right);
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
	root->right->left = newNode("+");
	root->right->right = newNode("/");

	root->left->left->left = newNode("+");
	root->left->left->right = newNode("4");
	root->left->right->left = newNode("-");
	root->left->right->right = newNode("2");
	root->right->left->left = newNode("*");
	root->right->left->right = newNode("2");
	root->right->right->left = newNode("8");
	root->right->right->right = newNode("4");

	root->left->left->left->left = newNode("/");
	root->left->left->left->right = newNode("3");
	root->left->right->left->left = newNode("7");
	root->left->right->left->left = newNode("7");
	root->left->right->left->right = newNode("5");
	root->right->left->left->left = newNode("4");
	root->right->left->left->right = newNode("/");

	root->left->left->left->left->left = newNode("3");
	root->left->left->left->left->right = newNode("1");
	root->right->left->left->right->left = newNode("6");
	root->right->left->left->right->right = newNode("1");

	cout << "ket qua: " << NLR(root) << endl;
	return 0;
}