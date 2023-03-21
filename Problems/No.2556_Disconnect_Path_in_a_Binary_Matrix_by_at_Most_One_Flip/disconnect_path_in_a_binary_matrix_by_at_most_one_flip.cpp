class Solution {
public:

    // Depth-First Search
    bool DFS(std::vector<std::vector<int>> &grid, int row, int col, int m, int n) {

        if ((row >= m) || (col >= n) || (grid[row][col] == 0)) return false;
        else if ((row == m-1) && (col == n-1)) return true;
        else {

            grid[row][col] = 0;
            return (DFS(grid, row+1, col, m, n) || DFS(grid, row, col+1, m, n));

        }

    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        // parameters
        int paths = 0;
        int m = grid.size(), n = grid[0].size();

        // start computing
        if (grid[0][0] == 0) return true;
        paths = DFS(grid, 0, 0, m, n);
        grid[0][0] = 1;
        paths += DFS(grid, 0, 0, m, n);

        return (paths < 2);

    }
};
