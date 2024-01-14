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

Node *firstNode(Node *root)
{
    //    Write your code here.
    if(root == nullptr || root->next == nullptr)
        return nullptr;
    Node *slow = root;
    Node *fast = root;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            slow = root;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
