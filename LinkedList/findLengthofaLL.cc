int length(Node *root)
{
	//Write your code here
    int count = 0;
    if(root == nullptr)
        return 0;
    Node *cur = root;
    while(cur)
    {
        count++;
        cur = cur->next;
    }
    return count;
}
