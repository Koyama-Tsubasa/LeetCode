class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // parameters
        int rowS = grid.size();
        int colS = grid[0].size();

        // start computing

        // calculate the first row & the first column
        for (int i=1; i<colS; i++) grid[0][i] += grid[0][i-1];
        for (int i=1; i<rowS; i++) grid[i][0] += grid[i-1][0];

        // calculate the other paths
        for (int i=1; i<rowS; i++)
            for (int j=1; j<colS; j++)
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);

        return grid[rowS-1][colS-1];

    }
};
