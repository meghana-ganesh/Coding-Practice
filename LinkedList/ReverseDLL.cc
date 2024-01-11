/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* root)
{   
    // Write your code here
    Node *rear = root; 
    Node *temp;
    while(rear->next)
    {
        temp = rear->prev;
        rear->prev = rear->next;
        rear->next = temp;
        rear = rear->prev;
    }
    temp = rear->prev;
    rear->prev = rear->next;
    rear->next = temp;
    root = rear;
    return root;
}
//1 2 3 4 5
//

