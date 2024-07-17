//TC:O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0, tot = 0, mins = 0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] != 0)
                    tot++;
                if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }
        while(!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            while(k--)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty())
                mins++;
        }
        if(tot == cnt)
            return mins;
        return -1;
    }
};
