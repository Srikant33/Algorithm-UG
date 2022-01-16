/*
Program: Generic Threaded Binary Tree
 1. Insert Node
 2. Display Nodes
Author: Kapil Sunil Zad
*/
#include<iostream>
using namespace std;
template<class T>
class Node
{
 Node<T> *left;
 T data;
 Node<T> *right;
 bool lthread;
 bool rthread;
public:
 Node(T value)
 {
 data = value;
 left = NULL;
 right = NULL;
 lthread = false;
 rthread = false;
 }

 void SetLeft(Node<T> * l)
 {
 left = l;
 }
 Node<T> *GetLeft()
 {
 return left;
 }
 void SetRight(Node<T> *r)
 {
 right = r;
 }
 Node<T> *GetRight()
 {
 return right;
 }
 void SetData(T value)
 {
 data = value;
 }
 T GetData()
 {
 return data;
 }
 void SetLeftThread(bool value)
 {
 lthread = value;
 }

 bool GetLeftThread()
 {
 return lthread;
 }
 void SetRightThread(bool value)
 {
 rthread = value;
 }
 bool GetRightThread()
 {
 return rthread;
 }
};
template<class T>
class ThreadedBinTree
{
 Node<T> * root;
public:
 ThreadedBinTree()
 {
 root = NULL;
 }

 void Insert(T data)
 {
 Node<T> *node = new Node<T>(data);

 if(root == NULL)
 {
 root = node;
 return;
 }
 Node<T> *ptr = root, *parent = NULL;
 while(ptr!=NULL)
 {
 if(data == ptr->GetData())
 {
 delete node;
 cout<<"Data already present.\n";
 return;
 }
 parent = ptr;

 if(data < ptr->GetData())
 {
 if(ptr->GetLeftThread())
 break;
 else
 ptr = ptr->GetLeft();
 }
 else
 {
 if(ptr->GetRightThread())
 break;
 else
 ptr = ptr->GetRight();
 }
 }
 if(ptr == NULL)
 {
 if(data < parent->GetData())
 {
 parent->SetLeft(node);
 node->SetRight(parent);
 node->SetRightThread(true);
 }
 else
 {
 parent->SetRight(node);
 node->SetLeft(parent);
 node->SetLeftThread(true);
 }
 }
 else
 {
 if(data < ptr->GetData())
 {
 node->SetLeft(ptr->GetLeft());
 node->SetLeftThread(true);
 node->SetRight(ptr);
 node->SetRightThread(true);
 ptr->SetLeft(node);
 ptr->SetLeftThread(false);
 }
 else
 {
 node->SetRight(ptr->GetRight());
 node->SetRightThread(true);
 node->SetLeft(ptr);
 node->SetLeftThread(true);
 ptr->SetRight(node);
 ptr->SetRightThread(false);
 }
 }
 }
 void Display()
 {
 if(root == NULL)
 {
 cout<<"Empty.\n";
 return;
 }
  Node<T> *p, *q;
 p = root;
 do
 {
 while(p != NULL)
 {
 q = p;
 if(p->GetLeftThread())
 break;
 else
 p = p->GetLeft();
 }
 cout<<q->GetData()<<" ";
 p = q->GetRight();
 while(q->GetRightThread())
 {
 cout<<p->GetData()<<" ";
 q = p;
 p = q->GetRight();

 }
 }while(p != NULL);
 }
};
int main()
{
 ThreadedBinTree<int> t;
 int option, data;
 do
 {
 cout<<"\n1. Insert\n";
 cout<<"2. Display\n";
 cout<<"3. Exit\n>> ";
 cin>>option;
 switch(option)
 {
 case 1:
 cout<<"Enter data: ";
 cin>>data;
 t.Insert(data);
 break;
 case 2:
 t.Display();
 cout<<endl;
 break;
 case 3: break;
 default:
 cout<<"Invalid option.\n";
 }

 }while(option != 3);
 return 0;
}
