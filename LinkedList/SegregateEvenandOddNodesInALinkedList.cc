//TC:O(N) SC:O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    //1 2
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *first = head;
        ListNode *newHead = reverseLL(slow->next);
        ListNode *second = newHead;
        while(second)
        {
            if(first->val != second->val)
            {
                slow->next = reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        slow->next = reverseLL(newHead);
        return true;
    }
};






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
