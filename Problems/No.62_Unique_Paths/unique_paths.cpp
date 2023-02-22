class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // parameters
        std::vector<std::vector<int>> AREA(m, std::vector<int> (n, 1));

        // start computing
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                AREA[i][j] = AREA[i-1][j] + AREA[i][j-1];

        return AREA[m-1][n-1];

    }
};
