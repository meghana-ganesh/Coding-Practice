//RECURSIVE
//TIME COMPLEXITY-O(N)
//SPACE COMPLEXITY-O(N)
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *newhead = reverseLinkedList(head->next);
    Node *cur = head->next;
    cur->next = head;
    head->next = nullptr;
    return newhead;
}


//ITERATIVE
//TIME COMPLEXITY:O(N),SPACE COMPLEXITY:O(N)
Node* reverseLinkedList(Node *root)
{
    // Write your code here
    Node *cur = root;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
    return root;
}

//TIME COMPLEXITY:O(N)+O(N) = O(2N)
//SPACE COMPLEXITY:O(N) - use of stack
#include<stack>
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    stack<int> st;
    Node *rear = head;
    while(rear)
    {
        st.push(rear->data);
        rear = rear->next;
    }
    rear = head;
    while(rear && !st.empty())
    {
        rear->data = st.top();
        st.pop();
        rear = rear->next;
    }
    return head;
}
