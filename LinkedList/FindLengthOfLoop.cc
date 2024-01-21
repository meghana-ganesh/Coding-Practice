//USING TORTOISE HARE:




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
