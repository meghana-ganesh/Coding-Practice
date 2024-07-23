//TC:O(N*M) + O(4*N*M) = O(N*M) //constant factors are dropped in big O notation
//TC:O(N*M) + O(N*M) - recursion stack space + ans copy array
class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<vector<int>>& image,int row,int col,int newColor,int iniColor,vector<int> &deltaRow,vector<int> &deltaCol)
    {
        ans[row][col] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {
                dfs(ans,image,nrow,ncol,newColor,iniColor,deltaRow,deltaCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<int>> ans = image;
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        dfs(ans,image,sr,sc,color,image[sr][sc],deltaRow,deltaCol);
        return ans;
    }
};


//USING BFS
class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m)
    {
        int iniColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = newColor;
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == iniColor && image[nrow][ncol] != newColor)
                {
                    image[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) 
            return image;
        int n = image.size();
        int m = image[0].size();
        bfs(image,sr,sc,color,n,m);
        return image;
    }
};
