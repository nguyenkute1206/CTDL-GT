#include<iostream>
#include<fstream>
#include<stack>
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

void getList(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* getNODE(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "khong tao duoc!";
        exit(0);
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

void addTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void DocFile(LIST& l)
{
    NODE* p;
    fstream input_file("data.txt");
    if (!input_file.is_open())
    {
        cout << "khong mo duoc file!";
        return;
    }
    while (!input_file.eof())
    {
        int n;
        input_file >> n;
        p = getNODE(n);
        addTail(l, p);
    }
    input_file.close();
}

void HienThi(LIST& l)
{
    if (l.pHead != NULL)
    {
        NODE* NODE = l.pHead;
        while (NODE != NULL)
        {
            cout << NODE->data << " ";
            NODE = NODE->pNext;
        }
    }
    cout << endl;
}

void GhiFile(LIST& l)
{
    ofstream file("data_quictsort.txt");

    if (file.is_open())
    {
        if (l.pHead != NULL)
        {
            NODE* NODE = l.pHead;
            while (NODE != NULL)
            {
                file << NODE->data << " ";
                NODE = NODE->pNext;
            }
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file de ghi!" << endl;
    }
}
NODE* partition(NODE* low, NODE* high)
{
    NODE* pivot = low;
    NODE* i = low;
    NODE* j = low->pNext;

    while (j != high->pNext)
    {
        if (j->data < pivot->data)
        {
            i = i->pNext;
            swap(i->data, j->data);
        }
        j = j->pNext;
    }
    swap(i->data, pivot->data);
    return i;
}
void quickSort(LIST& l) {
    if (l.pHead == NULL || l.pHead == l.pTail) 
    {
        return;
    }

    stack<pair<NODE*, NODE*>> s;
    s.push(make_pair(l.pHead, l.pTail));

    while (!s.empty()) 
    {
        pair<NODE*, NODE*> p = s.top();
        s.pop();

        NODE* low = p.first;
        NODE* high = p.second;

        if (low != high && low->pNext != high) {
            NODE* q = partition(low, high);
            s.push(make_pair(low, q));
            s.push(make_pair(q->pNext, high));
        }
    }
}
int main()
{
    LIST l;
    getList(l);
    DocFile(l);
    cout << "file da doc:";
    HienThi(l);
    quickSort(l);
    cout << "file da sap xep:";
    HienThi(l);
    GhiFile(l);
    return 0;
}
