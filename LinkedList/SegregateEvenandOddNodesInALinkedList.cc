/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* segregateEvenOdd(Node* head)
{
    // Write your code here
    Node *even = nullptr;
    Node *odd = nullptr;
    Node *evenTail = nullptr;
    Node *oddTail = nullptr;
    Node *current = head;
    while(current != nullptr)
    {
        if(current->data % 2 == 0)
        {
            if(!even)
            {
                even = current;
                evenTail = even;
            }
            else
            {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if(!odd)
            {
                odd = current;
                oddTail = odd;
            }
            else
            {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }
    if(even)
    {
        evenTail->next = odd;
        if(oddTail)
        {
            oddTail->next = nullptr;
        }
        return even;
    }
    return odd;
}
