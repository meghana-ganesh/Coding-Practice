//MERGESORT APPROACH
//Time complexity:O(logN*(N+N/2))
//SPACE COMPLEXITY:O(logN) for recursive stack space,as recursive depth is logN
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; //exception case
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *head1,Node *head2)
{
    Node *newhead = new Node();  // Dummy node for the merged list
    Node *curr = newhead;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        } 
        else 
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // If any list is remaining, append its elements
    if (head1 != nullptr) 
    {
        curr->next = head1;
    } 
    else 
    {
        curr->next = head2;
    }

    return newhead->next;
}
Node* sortList(Node* head)
{
    // Write your code here.
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *middle = findMiddle(head);
    Node *lefthead = head;
    Node *righthead = middle->next;
    middle->next = nullptr;
    lefthead = sortList(lefthead);
    righthead = sortList(righthead);
    return merge(lefthead,righthead);
}
