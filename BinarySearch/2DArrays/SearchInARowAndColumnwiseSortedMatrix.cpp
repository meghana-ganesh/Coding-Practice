bool searchElement(vector<vector<int>> &mat, int target)
{
    // Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    int row = 0,col = m-1;
    while(row < n && col >=0)
    {
        if(mat[row][col] == target)
            return true;
        else if(mat[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}
