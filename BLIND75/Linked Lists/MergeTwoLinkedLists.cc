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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *l1 = list1,*l2 = list2;
        ListNode *newList = new ListNode(0);
        ListNode *newHead = newList;
        while(l1 || l2)
        {
            if(l1 == NULL)
            {
                newList->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if(l2 == NULL)
            {
                newList->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                if(l1->val < l2->val)
                {
                    newList->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else
                {
                    newList->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            newList = newList->next;
        }
        return newHead->next;
    }
};
