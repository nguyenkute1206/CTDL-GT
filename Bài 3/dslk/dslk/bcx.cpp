#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cmath>
#include <iostream>
#include <string>
#include<ctype.h>
#include <string.h>
#include <conio.h>
using namespace std;
int n = 0;//biến toàn cục, đếm số lượng phần tử dslk
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
void init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE* getNode(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL; //không đủ bộ nhớ
    p->data = x;
    p->pNext = NULL;
    return p;
}
void addHead(LIST& l, NODE* new_ele)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = new_ele;
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
}
void addTail(LIST& l, NODE* new_ele)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = new_ele;
    else
    {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}
void input(list& l)
{
    int n;// số lượng node cần thêm
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;// data
        cin >> x;
        NODE* p = getNode(x);
        //addHead(l, p);
        addTail(l, p);
    }
}
void output(list l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        cout << k->data << "   ";
}
//tìm giá trị max trong linked list
int max(LIST l)
{
    int lc = l.pHead->data;
    for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext)// duyệt từ node thứ 2
        if (lc < k->data)
            lc = k->data;
    return lc;
}
//tính tổng lẻ các số trong single linked list
int tongLe(LIST l)
{
    int s = 0;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        if (k->data % 2 != 0)
            s += k->data;
    return s;
}
//đếm số chẵn
int demChan(LIST l)
{
    int count = 0;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        if (k->data % 2 == 0)
            count++;
    return count;
}
//tìm địa chỉ node lớn nhất
NODE* MaxAddress(LIST l)
{
    NODE* lc = l.pHead;
    for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext)
        if (lc->data < k->data)
            lc = k;
    return lc;
}
//sắp xếp tăng dần
void SapTang(LIST l)
{
    for (NODE* k = l.pHead; k->pNext != NULL; k = k->pNext)
        for (NODE* t = k->pNext; t != NULL; t = t->pNext)
            if (k->data > t->data)
            {
                int temp = k->data;
                k->data = t->data;
                t->data = temp;
            }
}
//thêm node p vào sau node q
void ThemNodePVaoSauNodeQ(LIST& l, NODE* p)
{
    int x;
    cout << "nhap gia tri node Q" << endl;
    cin >> x;
    NODE* q = getNode(x);
    //nếu dslk có 1 phần tử và data nó giống Q thì addtail
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
        addTail(l, p);
    else
    {
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
            if (q->data == k->data)
            {
                NODE* h = getNode(p->data);
                NODE* temp = k->pNext;
                h->pNext = temp;
                k->pNext = h;
            }
    }
}
//thêm node p trước sau node q
void ThemNodePVaoTruocNodeQ(LIST& l, NODE* p)
{
    int x;
    cout << "nhap gia tri node Q" << endl;
    cin >> x;
    NODE* q = getNode(x);
    //nếu dslk có 1 phần tử và data nó giống Q thì addHead
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
        addHead(l, p);
    else
    {
        NODE* g = new NODE;// node g giữ liên kết với node trước node q
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            if (q->data == k->data)
            {
                //them node p vao sau node g
                NODE* h = getNode(p->data);
                //NODE* temp = g->pNext;
                h->pNext = k;
                g->pNext = h;
            }
            g = k;// giữ node trước
        }
    }
}
//hàm thêm node p vào vị trí bất kì
void ThemNodePVaoViTriBatKy(LIST& l, NODE* p, int vitri, int n)
{

    //danh sách đang rỗng
    if (l.pHead == NULL || vitri == 1)
        //thêm node p vào đầu dslk
        addHead(l, p);
    else if (vitri == n + 1)
        addTail(l, p);// thêm node p vào cuối
    else// vị trí từ 2 đến n
    {
        int DemViTri = 0;
        NODE* g = new NODE;
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            DemViTri++;
            if (DemViTri == vitri)
            {
                NODE* h = getNode(p->data);
                h->pNext = k;
                g->pNext = h;
                break;//vị trí thì chỉ có 1 mà thôi, chạy nhiều cực
            }
            g = k;
        }
    }
}
void ThemNodePVaoViTriBatKyCach2(LIST& l, NODE* p, int vitri)
{
    //danh sách đang rỗng
    if (l.pHead == NULL || vitri == 1)
        //thêm node p vào đầu dslk
        addHead(l, p);
    else if (vitri == n + 1)
        addTail(l, p);// thêm node p vào cuối
    else// vị trí từ 2 đến n
    {
        int DemViTri = 0;
        NODE* g = new NODE;
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            DemViTri++;
            if (DemViTri == vitri)
            {
                NODE* h = getNode(p->data);
                h->pNext = k;
                g->pNext = h;
                break;//vị trí thì chỉ có 1 mà thôi, chạy nhiều cực
            }
            g = k;
        }
    }
}
void RemoveFirst(LIST& l)
{
    //nếu danh sách rỗng
    if (l.pHead == NULL)
        return;
    NODE* p = l.pHead;// node p là node sẽ xóa
    l.pHead = l.pHead->pNext;// cập nhật phead mới là phần tử kế
    delete p;
}
void RemoveLast(LIST& l)
{
    //nếu danh sách rỗng
    if (l.pHead == NULL)
        return;
    //danh sách có 1 phần tử
    if (l.pHead->pNext == NULL) //mình tự nghĩ l.pHead == l.pTail
    {
        RemoveFirst(l);//l.pHead = l.pTail=NULL
        return;
    }
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        if (k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext = NULL;
            l.pTail = k;// cập nhật lại ptail
            return;
        }
}
void Remove1NodeSauNodeQ(LIST& l, NODE* q)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        if (q->data == k->data)
        {
            NODE* g = k->pNext;//node này sẽ xóa
            k->pNext = g->pNext;
            delete g;
            //return;
        }
}
void Remove(LIST& l, int x)
{
    if (l.pHead == NULL)
        return;
    if (l.pHead->data == x)
    {
        RemoveFirst(l);
        return;
    }
    if (l.pTail->data == x)
    {
        RemoveLast(l);
        return;
    }
    NODE* g = new NODE;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == x)
        {
            g->pNext = k->pNext;
            delete k;
            return;
        }
        g = k;
    }
}
void menu(LIST& l)
{
    int LuaChon;
    while (true)// giá trị khác 0, nhập 0 là dừng
    {
        system("cls");//xóa màn hình
        cout << "Option 1: Them node vao cuoi danh sach" << endl;
        cout << "Option 2: Xuat danh sach" << endl;
        cout << "Option 3: Them node P vao sau node Q" << endl;
        cout << "Option 4: Them node P vao truoc node Q" << endl;
        cout << "Option 5: Them node P vao vi tri bat ky" << endl;
        cout << "Option 6: Xoa gia tri dau" << endl;
        cout << "Option 7: Xoa gia tri cuoi" << endl;
        cout << "Option 8: Xoa gia tri sau node q" << endl;
        cout << "Option 9: Xoa gia tri khoa k bat ky" << endl;
        cout << "Option 0: Thoat game" << endl;
        cout << "nhap lua chon" << endl;
        cin >> LuaChon;
        if (LuaChon < 0 || LuaChon>9)
        {
            cout << "nhap sai, vui long nhap lai:" << endl;
            system("pause");
        }
        else if (LuaChon == 1)
        {
            n++;//đếm ấy mà, cách 2
            cout << "nhap so can them: ";
            int x;
            cin >> x;
            NODE* p = getNode(x);
            addTail(l, p);
        }
        else if (LuaChon == 2)
        {
            output(l);
            system("pause");
        }
        else if (LuaChon == 3)
        {
            int x;
            cout << "nhap gia tri p can them vao sau node q" << endl;
            cin >> x;
            NODE* p = getNode(x);
            ThemNodePVaoSauNodeQ(l, p);
        }
        else if (LuaChon == 4)
        {
            int x;
            cout << "nhap gia tri p can them vao truoc node q" << endl;
            cin >> x;
            NODE* p = getNode(x);
            ThemNodePVaoTruocNodeQ(l, p);
        }
        else if (LuaChon == 5)
        {

            int x;
            cout << "nhap gia tri p can them: " << endl;
            cin >> x;
            NODE* p = getNode(x);
            int vitri;
            do
            {
                cout << "nhap vi tri can them: " << endl;
                cin >> vitri;
                if (vitri<1 || vitri >n + 1)
                {
                    cout << " nhap vi tri sai, nhap lai: " << endl;
                    system("pause");
                }
            } while (vitri<1 || vitri >n + 1);
            //cách 1
            //ThemNodePVaoViTriBatKy(l, p, vitri,n);
            //cách 2
            ThemNodePVaoViTriBatKyCach2(l, p, vitri);
            n++;
        }
        else if (LuaChon == 6)
            RemoveFirst(l);
        else if (LuaChon == 7)
            RemoveLast(l);
        else if (LuaChon == 8)
        {
            int x;
            cout << "nhap gia tri Q: ";
            cin >> x;
            NODE* q = getNode(x);
            Remove1NodeSauNodeQ(l, q);
        }
        else if (LuaChon == 9)
        {
            int x;
            cout << "nhap gia tri K: ";
            cin >> x;
            Remove(l, x);
        }
        else// tương ứng lựa chọn 0
            break;
    }
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    LIST l;
    init(l);// gọi hàm khởi tạo rồi hẵn vô menu
    menu(l);
    //system("pasue");
}

