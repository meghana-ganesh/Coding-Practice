//METHOD 1
//USING HASHING CONCEPT - MORE EFFICIENT
//Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
//Space Complexity: O(N) extra for hashing approach

class Solution {
public:
    void helper(int n,int col,vector<vector<string>> &ans,vector<string> &board,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) //traversing rows
        {
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[(n-1)+(col-row)] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[(n-1)+(col-row)] = 1;

                helper(n,col+1,ans,board,leftRow,lowerDiagonal,upperDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[(n-1)+(col-row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        vector<int> leftRow(2*n-1);
        vector<int> lowerDiagonal(2*n-1);
        vector<int> upperDiagonal(2*n-1);
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        helper(n,0,ans,board,leftRow,lowerDiagonal,upperDiagonal); // every recursive call of this goes columnwise
        return ans;
    }
};



//METHOD 2
//Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
//Space Complexity: O(N^2)

class Solution {
public:
    int isSafe(int n,int row,int col,vector<string> board)
    {
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0) //upper left diagonal        
        {
            if(board[row][col] == 'Q')
                return 0;
            row--; //upper left diagonal
            col--; //upper left diagonal
        }
        row = duprow;
        col = dupcol;
        while(row < n && col >= 0) //lower left diagonal
        {
            if(board[row][col] == 'Q')
                return 0;
            row++;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col >= 0) //horizontally to the left
        {
            if(board[row][col] == 'Q')
                return 0;
            col--;
        }
        return 1;
    }
    void helper(int n,int col,vector<vector<string>> &ans,vector<string> &board)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) //traversing rows
        {
            if(isSafe(n,row,col,board))
            {
                board[row][col] = 'Q';
                helper(n,col+1,ans,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        helper(n,0,ans,board); // every recursive call of this goes columnwise
        return ans;
    }
};
