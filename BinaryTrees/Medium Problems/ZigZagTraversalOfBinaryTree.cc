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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        q.push(root);
        int leftToRight = 1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                int ind = leftToRight ? i : size - i - 1;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                level[ind] = cur->val;
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};
