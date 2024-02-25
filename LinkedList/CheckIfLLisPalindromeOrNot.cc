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

