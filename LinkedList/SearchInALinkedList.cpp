int searchInLinkedList(Node<int> *root, int data) {
    // Write your code here.
    if(root == nullptr)
            return 0;
    Node<int> *cur = root;
    while(cur)
    {
        if(cur->data == data)
            return 1;
        cur = cur->next;
    }
    return 0;
}
