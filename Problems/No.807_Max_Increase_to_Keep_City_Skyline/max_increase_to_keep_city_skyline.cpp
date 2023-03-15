class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        // parameters
        int increased = 0;
        std::vector<int> max_col(grid[0].size(), 0), max_row(grid.size(), 0);

        // start computing
        // find the maximum of each column
        for (int col=0; col<grid[0].size(); col++)
            for (int row=0; row<grid.size(); row++)
                max_col[col] = std::max(max_col[col], grid[row][col]);

        // find the maximum of each row & start increasing
        for (int row=0; row<grid.size(); row++) {

            max_row[row] = *std::max_element(grid[row].begin(), grid[row].end());
            for (int col=0; col<grid[0].size(); col++) 
                increased += (std::min(max_row[row], max_col[col]) - grid[row][col]);
        
        }

        return increased;

    }
};
