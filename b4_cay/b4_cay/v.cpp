#include <iostream>
#include <stack>
#include <string>

using namespace std;

// định nghĩa cấu trúc nút cho cây nhị phân
struct Node {
    char data;
    Node* left;
    Node* right;
};

// tạo một nút mới trong cây nhị phân
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// chèn một nút vào cây nhị phân
void insertNode(Node*& root, char data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    if (isdigit(data)) {
        // Nếu data là số, ta tạo một nút mới và đưa nó vào cây nhị phân
        insertNode(root->right, data);
    }
    else {
        // Nếu data là toán tử, ta tạo một nút mới và đưa nó vào cây nhị phân
        insertNode(root->left, data);
    }
}

// tính toán giá trị biểu thức dựa trên cây nhị phân
int evaluateExpressionTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (isdigit(root->data)) {
        return root->data - '0';
    }
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);
    switch (root->data) {
    case '+':
        return leftVal + rightVal;
    case '-':
        return leftVal - rightVal;
    case '*':
        return leftVal * rightVal;
    case '/':
        return leftVal / rightVal;
    default:
        return 0;
    }
}

int main() {
    Node* root = NULL;
    string expression = "5*3*2+2";
    for (char c : expression) {
        insertNode(root, c);
    }
    cout << "Expression: " << expression << endl;
    int result = evaluateExpressionTree(root);
    cout << "Result: " << result << endl;
    return 0;
}
