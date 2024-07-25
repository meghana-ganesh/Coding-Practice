#include<iostream>
using namespace std;
class TreeNode
{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = right = NULL;
    }
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
void createBST(TreeNode *&root,int val)
{
    if(root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    else if(val <= root->val)
    {
        createBST(root->left,val);
    }
    else if(val > root->val)
    {
        createBST(root->right,val);
    }
}
void preorder(TreeNode *root)
{
    if(root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    TreeNode *root = NULL;
    createBST(root,10);
    createBST(root,14);
    createBST(root,8);
    createBST(root,7);
    createBST(root,13);
    createBST(root,9);
    preorder(root);
}

//    10
//  8     14
// 7 9   13
