//Time Complexity:  O(m*n*4^k), where “K” is the length of the word. And we are searching for the letter m*n times in the worst case. 
//Here 4 in 4^k is because at each level of our decision tree we are making 4 recursive calls which equal 4^k in the worst case.

//Space Complexity: O(K), Where k is the length of the given words.
class Solution {
public:
    bool helper(vector<vector<char>> &board,string word,int row,int col,int ind,int m,int n)
    {
        if(ind == word.length())
            return true;
        if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[ind] || board[row][col] == '!')
            return false;

        char c = board[row][col];
        board[row][col] = '!';
        
        int top = helper(board,word,row-1,col,ind+1,m,n);
        int bottom = helper(board,word,row+1,col,ind+1,m,n);
        int right = helper(board,word,row,col+1,ind+1,m,n);
        int left = helper(board,word,row,col-1,ind+1,m,n);

        board[row][col] = c;

        return top || bottom || right || left;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(helper(board,word,i,j,0,board.size(),board[0].size()))
                    return true;
            }
        }
        return false;
    }
};
