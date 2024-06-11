//TC:O(H) 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
            return NULL;
        TreeNode *cur = root;
        while(cur)
        {
            if(p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else if(p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }
        return cur;
    }
};
