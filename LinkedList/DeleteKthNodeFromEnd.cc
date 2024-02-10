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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if(head->next == nullptr && K == 0)
        return nullptr;
    Node *rear = head;
    Node *prev = nullptr;
    int count = 0;
    while(rear)
    {
        rear = rear->next;
        count++;
    }
    int len = count;
    count = 0;
    rear = head;
    if(len-K == 0)
        return head->next;
    while(rear)
    {
        if(len - K == count)
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
//3-2 = 1 == 
//1 2 3
