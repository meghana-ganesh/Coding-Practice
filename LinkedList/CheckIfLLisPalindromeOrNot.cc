//Brute Force
//O(2*N)
#include<stack>
bool isPalindrome(Node *head)
{
    // write your code here
    if(head == nullptr || head->next == nullptr)
          return true;
    stack<Node*> st;
    Node *temp = head;
    while(temp != NULL)
    {
        st.push(temp);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL && !st.empty())
    {
        Node *tos = st.top();
        if(temp->data != tos->data)
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

//Optimized approach
//O(N) without additional space
Node* reverseLL(Node *head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *cur = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
//1 2 3 4
bool isPalindrome(Node *head)
{
    // write your code here
    Node *slow = head;
    Node *fast = head;
    Node *cur = head;
    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *revhead = reverseLL(slow->next);
    Node *first = head;
    Node *second = revhead;
    while(second)
    {
        if(first->data != second->data)
        {
            reverseLL(revhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(revhead);
    return true;
}
