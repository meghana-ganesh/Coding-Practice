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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *even = nullptr;
        ListNode *odd = nullptr;
        ListNode *evenTail = nullptr;
        ListNode *oddTail = nullptr;
        ListNode *current = head;
        int count = 0;
        while(current != nullptr)
        {
            if(count % 2 == 0)
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
            count++;
        }
        //concantenate the even and odd indexed lists
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
};
