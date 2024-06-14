//ITERATIVE SOLUTION - TC:O(N) SC:O(1)
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
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
};

//TC:O(N) SC:O(N)
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
            return head;
        ListNode *newHead = head; //1->2->3
        if(head->next)
        {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;
    }
};
