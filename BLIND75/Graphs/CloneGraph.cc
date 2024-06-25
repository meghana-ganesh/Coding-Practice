//TC:O(N) where N = E+V
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node,unordered_map<Node*,Node*> &mpp)
    {
        Node *clone = new Node(node->val);
        mpp[node] = clone;
        vector<Node*> neighbor;
        for(auto it: node->neighbors)
        {
            if(mpp.find(it) != mpp.end())
            {
                neighbor.push_back(mpp[it]);
            }
            else
            {
                neighbor.push_back(dfs(it,mpp));
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*,Node*> mpp;
        if(node == NULL)
            return NULL;
        return dfs(node,mpp);
    }
};
