//TC:O(N)
//SC:O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &V)
    {
        TreeNode *rear = root;
        if(rear)
        {
            inorder(rear->left,V);
            V.push_back(rear->val);
            inorder(rear->right,V);
        }
    }
    int getMinimumDifference(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        vector<int> V;
        inorder(root,V);
        int minVal = INT_MAX;
        for(int i=1;i<V.size();i++)
        {
            minVal = min(minVal,abs(V[i] - V[i-1]));
        }
        return minVal;
    }
};
