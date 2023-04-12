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
void GetList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* GetNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "khong tao duoc NODE!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Add_Tail(LIST& l, NODE* p)
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
void Doc_File(LIST& l)
{
	NODE* p;
	ifstream input_file("data.txt");
	if (!input_file.is_open())
	{
		cout << "khong doc duoc file";
		
	}
	while (!input_file.eof())
	{
		int n;
		input_file >> n;
		p = GetNODE(n);
		Add_Tail(l,p);
	}
	input_file.close();
}
void Xuat_MH(LIST& l)
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
void Ghi_File(LIST& l)
{
	ofstream output_file("data_bubble_sort.txt");
	if (output_file.is_open())
	{
		if (l.pHead != NULL)
		{
			NODE* NODE = l.pHead;
			while (NODE != NULL)
			{
				output_file << NODE->data << " ";
				NODE = NODE->pNext;
			}
		}
		cout << endl;
		output_file.close();
	}
	else
	{
		cout << "khong tao duoc file";
	}
}
NODE* search(LIST& l)
{
	NODE* p;
	p = l.pHead;
}
int main()
{
	LIST l;
	GetList(l);
	Doc_File(l);
	Xuat_MH(l);
	system("pause");
	return 0;
}