//TORTOISE HARE PROBLEM
//TIME COMPLEXITY:O(N/2)
Node *findMiddle(Node *head)
{
    // Write your code here
    Node *slow = head;
    Node *fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


//TIME COMPLEXITY:O(N)+O(N/2)
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

