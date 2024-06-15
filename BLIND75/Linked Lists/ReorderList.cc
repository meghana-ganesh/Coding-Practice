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
    ListNode* reverseList(ListNode *head)
    {
        if(head == NULL)
            return NULL;
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nxt;
        while(cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *rev;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        rev = reverseList(slow->next);
        slow->next = NULL;
        ListNode *first = head;
        ListNode* second = rev;
        ListNode *tmp1,*tmp2;
        while(second)
        {
            tmp1 = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
