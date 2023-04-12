#include <iostream>
#include <stack>
using namespace std;

// Khai báo cấu trúc của node trong danh sách liên kết
struct NODE {
    int data;
    NODE* pNext;
};

// Hàm tạo một node mới với giá trị data
NODE* new_node(int data) {
    NODE* temp = new NODE;
    temp->data = data;
    temp->pNext = NULL;
    return temp;
}

// Hàm tách danh sách liên kết thành hai phần, bên trái và bên phải của chỉ mục chốt.
NODE* partition_linked_list(NODE* head, NODE* tail, NODE** new_head, NODE** new_tail) {
    NODE* pivot = tail;
    NODE* pPre = NULL;
    NODE* cur = head;
    NODE* end = tail;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*new_head == NULL) {
                *new_head = cur;
            }
            pPre = cur;
            cur = cur->pNext;
        }
        else {
            if (pPre) {
                pPre->pNext = cur->pNext;
            }
            NODE* temp = cur->pNext;
            cur->pNext = NULL;
            end->pNext = cur;
            end = cur;
            cur = temp;
        }
    }

    if (*new_head == NULL) {
        *new_head = pivot;
    }

    *new_tail = end;
    return pivot;
}

// Hàm sắp xếp danh sách liên kết bằng thuật toán quicksort
void quick_sort_linked_list(NODE* head, NODE* tail) {
    if (head == NULL || tail == NULL || head == tail) {
        return;
    }

    stack<NODE*> s;
    s.push(head);
    s.push(tail);

    while (!s.empty()) {
        NODE* right = s.top();
        s.pop();
        NODE* left = s.top();
        s.pop();

        NODE* new_head = NULL;
        NODE* new_tail = NULL;

        NODE* pivot = partition_linked_list(left, right, &new_head, &new_tail);

        if (new_head != pivot) {
            s.push(new_head);
            s.push(pivot->pNext);
        }

        if (new_tail != pivot) {
            s.push(pivot);
            s.push(new_tail);
        }
    }
}

// Hàm in ra các phần tử trong danh sách liên kết
void print_linked_list(NODE* head) {
    while (head) {
        cout << head->data << " ";
        head = head->pNext;
    }
    cout << endl;
}

// Hàm main để kiểm tra chương trình
int main() {
    NODE* head = new_node(5);
    head->pNext = new_node(3);
    head->pNext->pNext = new_node(9);
    head->pNext->pNext->pNext = new_node(2);
    head->pNext->pNext->pNext->pNext = new_node(7);
    head->pNext->pNext->pNext->pNext->pNext = new_node(1);

    cout << "Danh sach lien ket truoc khi sap xep: ";
    print_linked_list(head);

    quick_sort_linked_list(head, NULL);

    cout << "Danh sach lien ket" << endl;
    print_linked_list(head);
    return 0;
}
