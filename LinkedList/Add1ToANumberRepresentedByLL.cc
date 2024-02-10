/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *insertFront(Node *head,int data)
{
    Node *temp = new Node();
    if(head == nullptr)
    {
        temp->data = data;
        return temp;
    }
    temp->data = data;
    temp->next = head;
    return temp;
}
Node *reverseLL(Node *head)
{
    Node *revList = nullptr;
    Node *rear = head;
    while(rear)
    {
        revList = insertFront(revList,rear->data);
        rear = rear->next;
    }
    return revList;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = 1;
    Node *revList = reverseLL(head);
    //9 9
    Node *rear = revList;
    while(rear)
    {
        int val = rear->data;
        rear->data = (val + carry) % 10;
        carry = (val + carry)/10; //
        rear = rear->next;
    }
    revList = reverseLL(revList);
    if(carry == 1)
        revList = insertFront(revList,1);
    return revList;
}
