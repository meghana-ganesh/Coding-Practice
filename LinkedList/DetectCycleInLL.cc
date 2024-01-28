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

bool detectCycle(Node *root)
{
	//	Write your code here
    if(root == nullptr || root->next == nullptr)
        return false;
    Node *slow = root;
    Node *fast = root;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}


//TIME COMPLEXITY: O(N*2*LOG(N))
//SPACE COMPLEXITY: O(N)
#include<map>
bool detectCycle(Node *head)
{
	//	Write your code here
    map<Node*,int> mpp;
    Node *temp = head;
    while(temp)
    {
        if(mpp.find(temp) != mpp.end())
            return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}
