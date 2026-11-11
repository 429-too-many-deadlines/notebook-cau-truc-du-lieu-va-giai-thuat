#include <iostream>
using namespace std;

// Bước 1: Định nghĩa Node
struct Node
{
    int data;
    Node *pNext;
};

// Bước 2: Cấp phát vùng nhớ để lưu giá trị cần lưu trữ
Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;

    return p;
}

// Bước 3: Định nghĩa list
struct List
{
    Node *pHead;
    Node *pTail;
};

// Bước 4: Khởi tạo list
void initList(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == nullptr && l.pTail == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pHead == nullptr && l.pTail == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printList(List l)
{
    for (Node *p = l.pHead;; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

int main()
{
    Node *p1 = initNode(10);
    Node *p2 = initNode(79);
    List l;
    initList(l);
    addHead(l, p1);
    addTail(l, p2);
    addTail(l, initNode(39));

    printList(l);

    return 0;
}