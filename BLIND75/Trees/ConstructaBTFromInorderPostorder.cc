//TC:O(N)
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
   void createMapping(map<int,int>&mp,vector<int>inorder,int n){
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
    }

     TreeNode* solve(vector<int>postorder,vector<int>inorder,int &postOrderInd,int inorderStart,int inorderEnd,int n,map<int,int>&mp){
        if(postOrderInd<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=postorder[postOrderInd--];
        TreeNode* root=new TreeNode(element);
        int pos=mp[element];
        root->right=solve(postorder,inorder,postOrderInd,pos+1,inorderEnd,n,mp);
        root->left=solve(postorder,inorder,postOrderInd,inorderStart,pos-1,n,mp);
       // root->right=solve(preorder,inorder,postOrderInd,pos+1,inorderEnd,n,mp);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=postorder.size();
        int postOrderInd=n-1;
        map<int,int>mp;
        createMapping(mp,inorder,n);
        TreeNode* ans=solve(postorder,inorder,postOrderInd,0,n-1,n,mp);
        return ans;



    }
};
