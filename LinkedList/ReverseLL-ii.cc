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
TC(O(right - left + 1 +left-1))
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
            return head;
        ListNode *prevLeft = NULL;
        ListNode *cur = head;
        for(int i=0;i<left-1;i++)
        {
            prevLeft = cur;
            cur = cur->next;
        }
        ListNode *tail = cur;
        ListNode *prev = NULL;
        ListNode *next = cur->next;
        for(int i=0;i<right-left+1;i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (prevLeft != NULL) {
            prevLeft->next = prev;
        } 
        else {
            head = prev;  // This handles the case when reversal starts at the head
        }
        tail->next = cur;
        return head;
    }
};
