//USING TORTOISE HARE:O(N+C) (C is the size of the cycle,which in practice if is <<< N then TC = O(N))
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
int findLength(Node *slow,Node *fast)
{
    int count = 1;
    fast = fast->next;
    while(slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int lengthOfLoop(Node *head)
{
    // Write your code here
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return findLength(slow,fast);
    }
    return 0;
}





//USING HASHMAP:TIME COMPLEXITY:O(N*2*log(N)),PARTIALLY ACCEPTED
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
#include<map>
int lengthOfLoop(Node *head)
{
    // Write your code here
    map<Node*,int> mpp;
    Node *temp = head;
    int timer = 1;
    while(temp != NULL)
    {
        if(mpp.find(temp) != mpp.end())
        {
            int value = mpp[temp];
            return timer-value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}
