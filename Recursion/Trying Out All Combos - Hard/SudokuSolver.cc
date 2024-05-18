//Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
//Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
class Solution {
public:
    bool isPossible(vector<vector<char>> &board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == c)
                return false;
            else if(board[row][i] == c)
                return false;
            else if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) //3*3 sub-box
                return false;
        }
        return true;
    }
    bool helper(vector<vector<char>> &board)
    {
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1';c <= '9';c++)
                    {
                        if(isPossible(board,i,j,c))
                        {
                            board[i][j] = c;
                            if(helper(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        helper(board);
    }
};
