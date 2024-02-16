/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k)
{
    // Write your code here
    Node *rear = head;
    int alldeleted = 0;
    while(rear)
    {
        if(rear->data == k)
        {
            if(rear->prev != nullptr && rear->next != nullptr)
            {
                Node *temp = rear;
                temp->prev->next = temp->next;
                delete temp;
            }
            else if(rear->prev == nullptr && rear->next != nullptr)
            {
                //first node
                Node *temp = rear;
                head = temp->next;
                temp->next->prev = nullptr;
                delete temp;
            }
            else if(rear->next == nullptr && rear->prev != nullptr)
            {
                //last node
                rear->prev->next = nullptr;
                delete rear;
            }
        }
        else
        {
            alldeleted = 1;
        }
        rear = rear->next;
    }
    if(alldeleted == 0)
        return nullptr;
    else
        return head;
}
