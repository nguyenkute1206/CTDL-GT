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

    void addHead(int value) 
    {
        Node* new_node = new Node(value);
        if (head == nullptr) 
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void print()
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void shakerSort()
    {
        Node* left = head;
        Node* right = tail;
        while (left != right )
        {
            Node* sh = left;
            while (sh != right) 
            {
                if (sh->data > sh->next->data)
                {
                    swap(sh->data, sh->next->data);
                }
                sh = sh->next;
            }
            right = right->prev;
            while (sh != left) 
            {
                if (sh->data < sh->prev->data)
                {
                    swap(sh->data, sh->prev->data);
                }
                sh = sh->prev;
            }
            left = left->next;
        }
    }
};

int main() {
    LinkedList list;
    list.addHead(2);
    list.addHead(4);
    list.addHead(5);
    list.addHead(9);
    list.addHead(8);
    cout << "Danh sach truoc khi sap xep: ";
    list.print();
    list.shakerSort();
    cout << "Danh sach sau khi sap xep: ";
    list.print();
    return 0;
}
