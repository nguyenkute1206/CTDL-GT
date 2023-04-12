#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

void KhoiTao(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* KhoiTaoNODE(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "\nkhong khoi tao duoc!";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p; 
}

void ThemVaoDau(LIST& l, NODE* p)
{
    if (l.pHead == NULL) 
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void xuat(LIST l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext) 
    {
        cout << k->data << " ";
    }
}

void selectionSort(LIST& l) {
    NODE* p, * q, * min;
    int tmp;

    for (p = l.pHead; p != NULL; p = p->pNext)
    {
        min = p;

        for (q = p->pNext; q != NULL; q = q->pNext) 
        {
            if (q->data < min->data)
            {
                min = q;
            }
        }
        if (min != p)
        {
            tmp = min->data;
            min->data = p->data;
            p->data = tmp;
        }
    }
}

int main()
{
    LIST l;
    KhoiTao(l);
    int n;
    cout << "Nhap so phan tu trong danh sach: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        NODE* p = KhoiTaoNODE(x);
        ThemVaoDau(l, p);
    }
    cout << "Danh sach truoc khi sap xep: ";
    xuat(l);
    selectionSort(l);
    cout << "\nDanh sach sau khi sap xep: ";
    xuat(l);

    return 0;
}