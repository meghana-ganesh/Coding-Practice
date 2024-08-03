/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//TC:O(N) + O(N) = O(N)
//SC:O(1)
class Solution {
public:
    ListNode *findIntersection(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *meet = findIntersection(head);
        ListNode *start = head;
        if(meet == NULL || head == NULL)
            return NULL;
        while(start != meet)
        {
            start = start->next;
            meet = meet->next;
        }
        return start;
    }
};
