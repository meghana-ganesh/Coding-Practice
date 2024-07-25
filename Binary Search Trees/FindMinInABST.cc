//O(H) - height of tree

class Solution {
  public:
    void helper(Node* root,int &minVal)
    {
        if(root == NULL)
            return;
        if(root->left)
        {
            minVal = min(minVal,root->left->data);
            helper(root->left,minVal);
        }
    }
    int minValue(Node* root) 
    {
        // Code here
        if(root == NULL)
            return -1;
        int minVal = root->data;
        helper(root,minVal);
        return minVal;
    }
};
//  10
// 8
//7 9


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.minValue(root) << endl;
    }
    return 1;
}
// } Driver Code Ends
