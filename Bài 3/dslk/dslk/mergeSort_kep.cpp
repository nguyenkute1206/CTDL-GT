#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) 
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;
    Node* tail;
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void addHead(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void print() {
        Node* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node* merge(Node* left, Node* right) {
        Node* p = nullptr;
        if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;

        if (left->data <= right->data) {
            p = left;
            p->next = merge(left->next, right);
            p->next->prev = p;
            p->prev = nullptr;
        }
        else {
            p = right;
            p->next = merge(left, right->next);
            p->next->prev = p;
            p->prev = nullptr;
        }
        return p;
    }

    void mergeSort(Node** head_ref) {
        Node* head = *head_ref;
        Node* left;
        Node* right;

        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        left = head;
        right = head->next;
        while (right != nullptr)
        {
            right = right->next;
            if (right != nullptr) 
            {
                left = left->next;
                right = right->next;
            }
        }
        right = left->next;
        left->next = nullptr;
        mergeSort(&head);
        mergeSort(&right);

        *head_ref = merge(head, right);
    }
    void mergeSort()
    {
        mergeSort(&head);
    }
};

int main() {
    LinkedList list;
    int arr[] = { 4, 6, 8, 10,1,2,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        list.addHead(arr[i]);
    }
    cout << "Danh sach truoc khi sap xep: ";
    list.print();
    list.mergeSort();
    cout << "Danh sach sau khi sap xep: ";
    list.print();
    return 0;
}
