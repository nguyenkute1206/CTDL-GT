#include<iostream>
#include<fstream>
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
		cout << "khong khoi tao duoc";
		return NULL;
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
	ifstream input("data.txt");
	if (!input.is_open())
	{
		cout << "khong doc duoc file";
	}
	while (!input.eof())
	{
		int n;
		input >> n;
		p = getNODE(n);
		addTail(l,p);
	}
	input.close();
}
void GhiFile(LIST& l)
{
	ofstream output("data_bubble.txt");
	if (output.is_open())
	{
		if (l.pHead != NULL)
		{
			NODE* NODE = l.pHead;
			while (NODE != NULL)
			{
				output << NODE->data << " ";
				NODE = NODE->pNext;
			}
		}
		output.close();
	}
	else
	{
		cout << "khong tao duoc file!";
	}
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bubble_Sort(LIST& l)
{
	if (l.pHead == NULL || l.pHead == l.pTail)
		return;

	NODE* node1 = l.pHead;
	while (node1 != NULL && node1 != l.pTail)
	{
		NODE* node2 = node1->pNext;
		bool swapped = false; 
		while (node2 != NULL)       
		{
			if (node1->data > node2->data)
			{
				swap(node1->data, node2->data);
				swapped = true;
			}
			node2 = node2->pNext;
		}
		if (!swapped) 
			break;
		node1 = node1->pNext;
	}
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
int main()
{
	LIST l;
	getList(l);
	DocFile(l);
	bubble_Sort(l);
	GhiFile(l);
	HienThi(l);
	system("pause");
	return 0;
}