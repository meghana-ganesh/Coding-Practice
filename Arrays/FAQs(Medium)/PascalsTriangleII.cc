//TC: O(rowIndex)
vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long current = 1;
        result.push_back(1);
 
        // Generate each next coefficient from the previous coefficient.
        for (int col = 1; col <= rowIndex; col++) {
            current = current * (rowIndex - col + 1) / col;
 
            // Final values fit in int under the given constraints.
            result.push_back(current);
        }
 
        return result;
    }

//TC:O(N^2)
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> triangle;
        for(int row=0;row <= rowIndex;row++)
        {
            vector<int> current(row+1,1);
            for(int col = 1;col < row; col++)
            {
                current[col] = triangle[row-1][col-1] + triangle[row-1][col];
            }
            triangle.push_back(current);
        }
        return triangle[rowIndex];
    }
};
