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

Node* deleteMiddle(Node* head)
{
    // Write your code here.
    Node *rear = head;
    Node *prev = nullptr;
    int count = 0;
    while(rear)
    {
        rear = rear->next;
        count++;
    }
    int len = count;
    rear = head;
    count = 0;
    len = len/2;
    if(head->next == nullptr)
        return nullptr;
    while(rear)
    {
        if(count == len)
        {
            prev->next = rear->next;
            rear = rear->next;
            break;
        }
        prev = rear;
        rear = rear->next;
        count++;
    }
    return head;
}
