//TC:O(N)+O(H)+O(H)
//O(N) to reach leaves,O(H) for left and O(H) for right
// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    int isLeaf(Node *root)
    {
        if(root->left == NULL && root->right == NULL)
            return 1;
        return 0;
    }
    void addLeft(Node *root,vector<int> &res)
    {
        Node *cur = root->left;
        while(cur)
        {
            if(!isLeaf(cur))
                res.push_back(cur->data);
            if(cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    void addLeaves(Node *root,vector<int> &res)
    {
        Node *cur = root;
        if(isLeaf(cur))
        {
            res.push_back(cur->data);
            return;
        }
        if(cur->left)
            addLeaves(cur->left,res);
        if(cur->right)
            addLeaves(cur->right,res);
    }
    void addRight(Node *root,vector<int> &res)
    {
        Node *cur = root->right;
        vector<int> temp;
        while(cur)
        {
            if(!isLeaf(cur))
                temp.push_back(cur->data);
            if(cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> res;
        if(!root)
            return res;
        if(!isLeaf(root))
            res.push_back(root->data);
        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
