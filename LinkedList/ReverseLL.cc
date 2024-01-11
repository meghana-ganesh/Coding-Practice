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
//1 2 3 4
Node* reverseLinkedList(Node *root)
{
    // Write your code here
    if(root == nullptr || root->next == nullptr)
        return root;
    Node *cur = root;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
    return root;
}
