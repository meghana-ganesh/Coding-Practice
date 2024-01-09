/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) 
{
    // Write your code here
    if(arr.size() == 0)
        return nullptr;
    Node *root = new Node(arr[0]);
    Node *cur = root;
    for(int i=1;i<arr.size();i++)
    {
        cur->next = new Node(arr[i]);
        cur->next->prev = cur;
        cur = cur->next;
    }
    return root;
}
