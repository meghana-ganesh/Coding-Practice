#include<iostream>

class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int x)
    {
        data = x;
        next = nullptr;
    }

    Node(int x,Node* next)
    {
        data = x;
        next = next;
    }
};

class LinkedList
{
    public:
    void insertFront(Node *&root,int data)
    {
        Node* temp = new Node(data);
        if(root == nullptr)
        {
            root = temp;
            return;
        }
        temp->next = root;
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
        Node *cur = root;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = nullptr;
    }
    void deleteFront(Node *&root)
    {
        if(root == nullptr)
            return;
        Node *head = root;
        root = root->next;
        free(head);
    }
    void deleteLast(Node *&root)
    {
        if(root == nullptr)
            return;
        Node *cur = root;
        Node *prev;
        while(cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        free(cur->next);
    }
    void display(Node *root)
    {
        Node *rear = root;
        while(rear)
        {
            printf("%d ",rear->data);
            rear = rear->next;
        }
        printf("\n");
    }
};

int main()
{
    LinkedList list;
    Node *root = nullptr;
    list.insertFront(root,4);
    list.insertFront(root,3);
    list.insertFront(root,2);
    list.insertFront(root,1);
    list.display(root);
    list.insertLast(root,5);
    list.insertLast(root,6);
    list.display(root);
    list.deleteFront(root);
    list.deleteFront(root);
    list.display(root);
    list.deleteLast(root);
    list.deleteLast(root);
    list.display(root);
    return 0;
}
