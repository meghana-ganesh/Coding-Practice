/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *root)
{
    // Write your code here
    int flag = 0;
    if(root == nullptr)
        return root;
    Node *rear = root;
    Node *prev = nullptr;
    while(rear->next)
    {
        prev = rear;
        rear = rear->next;
    }
    //handle case where length of LL is only 1 otherwise seg fault will occur
    if(prev == nullptr)
    {
        free(rear);
        return nullptr;
    }
    Node *temp = rear;
    prev->next = nullptr;
    rear->prev = nullptr;
    free(temp);
    return root;
}
