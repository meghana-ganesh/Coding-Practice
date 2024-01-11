#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next,*prev;
    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
    Node(int data,Node *prev,Node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DLL
{
    public:
    void insertFront(Node *&root,int data)
    {
        Node *temp = new Node(data);
        if(root == nullptr)
        {
            root = temp;
            return;
        }
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    void insertLast(Node *&root,int data)
    {
        Node *temp = new Node(data);
        if(root == nullptr)
        {
            root = temp;
            return;
        }
        Node *rear = root;
        while(rear->next)
        {
            rear = rear->next;
        }
        rear->next = temp;
        temp->prev = rear;
    }
    void deleteFront(Node *&root)
    {
        if(root == nullptr)
            return;
        Node *temp = root;
        root->next->prev = nullptr;
        root = root->next;
        free(temp);
    }
    void deleteLast(Node *&root)
    {
        if(root == nullptr)
            return;
        Node *rear = root;
        Node *prev;
        while(rear->next)
        {
            prev = rear;
            rear = rear->next;
        }
        //handle case where length of LL is only 1 otherwise seg fault will occur
        if(prev == nullptr)
        {
            free(rear);
        }
        Node *temp = rear;
        prev->next = nullptr;
        rear->prev = nullptr;
        free(temp);
    }
    void display(Node *root)
    {
        Node *rear = root;
        while(rear)
        {
            cout << rear->data << " ";
            rear = rear->next;
        }
        cout << "\n";
    }
};

int main()
{
    Node *root = nullptr;
    DLL list;
    list.insertFront(root,4);
    list.insertFront(root,3);
    list.insertFront(root,2);
    list.insertFront(root,1);
    list.insertLast(root,5);
    list.insertLast(root,6);
    list.display(root);
    list.deleteFront(root);
    list.deleteFront(root);
    list.display(root);
    list.deleteLast(root);
    list.deleteLast(root);
    list.deleteLast(root);
    list.deleteLast(root);
    list.display(root);
}
