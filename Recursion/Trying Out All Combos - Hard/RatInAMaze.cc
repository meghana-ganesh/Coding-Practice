//TIME COMPLEXITY:O(4^(n*n)) - each cell can branch into 4 possible directions - but v loose upper bound cuz we prune paths where cells are revisited or blocked
//SPACE COMPLEXITY:O(n^2) - recursive stack space - the maximum depth of the recursion tree is equal to the number of cells in the maze.
//own solution worked
class Solution{
    public:
    void helper(vector<vector<int>> m,vector<string> &ans,int n,int row,int col,string path)
    {
        if(row == n-1 && col == n-1 && m[row][col] == 1)
        {
            ans.push_back(path);
            return;
        }
        if(row < 0 || col < 0 || row == n || col == n || m[row][col] != 1)
            return;
        int val = m[row][col];
        m[row][col] = -1;
        
        helper(m,ans,n,row-1,col,path + 'U'); //top
        
        helper(m,ans,n,row+1,col,path + 'D'); //bottom
        
        helper(m,ans,n,row,col+1,path + 'R'); //right
        
        helper(m,ans,n,row,col-1,path + 'L'); //left
        
        m[row][col] = val;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        // Your code goes here
        vector<string> ans;
        string path;
        if (m[0][0] == 0 || m[n-1][n-1] == 0) 
            return ans;
        helper(m,ans,n,0,0,path);
        return ans;
    }
};
