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
void DocFile(LIST &l)
{
	NODE* p;
	fstream input_file("data.txt");
	if (!input_file.is_open())
	{
		cout << "khong mo duoc file!";
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
void GhiFile(LIST& l)
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
}
int main()
{
	LIST l;
	getList(l);
	DocFile(l);
	cout << "file da doc:";
	GhiFile(l);
	system("pause");
	return 0;
}