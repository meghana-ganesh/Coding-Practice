/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include<cmath>
Node *findMiddle(Node *root) 
{
    // Write your code here
    int len = 0;
    int count = 0;
    if(root->next == nullptr)
        return root;
    Node *rear = root;
    while(rear)
    {
        len++;
        rear = rear->next;
    }
    rear = root;
    int req=len/2+1;
    while(rear)
    {
        count++;
        if(count == req)
            return rear;
        rear = rear->next;
    }
    return nullptr;
}

