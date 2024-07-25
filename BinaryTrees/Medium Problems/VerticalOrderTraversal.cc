//TC:O(N) + O(NlogN)-for sorting
//SC:O(N) for every level
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
class List
{
    public:
        int val;
        int row;
        int col;
    List()
    {
        val = 0;
        row = col = 0;
    }
    List(int val,int row,int col)
    {
        this->val = val;
        this->row = row;
        this->col = col;
    }
};
class Solution {
public:
    void dfs(TreeNode* root,int row,int col,vector<List> &mpp)
    {
        if(root == NULL)
            return;
        mpp.push_back({root->val,row,col});
        dfs(root->left,row+1,col-1,mpp);
        dfs(root->right,row+1,col+1,mpp);
    }
    bool static comp(List &a,List &b)
    {
        if(a.col != b.col)
            return a.col < b.col;
        if(a.row != b.row)
            return a.row < b.row;
        return a.val < b.val;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<List> mpp;
        dfs(root,0,0,mpp);
        sort(mpp.begin(),mpp.end(),comp);
        for(auto it:mpp)
        {
            cout << it.val << " ";
        }
        vector<vector<int>> ans;
        vector<int> lst;
        int prevcol = mpp[0].col;
        for(auto it: mpp)
        {
            if(it.col == prevcol)
            {
                lst.push_back(it.val);
            }
            else
            {
                ans.push_back(lst);
                lst.clear();
                prevcol = it.col;
                lst.push_back(it.val);
            }
        }
        if(!lst.empty())
        {
            ans.push_back(lst);
        }
        return ans;
    }
};
