class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // parameter
        int rowS = obstacleGrid.size();
        int colS = obstacleGrid[0].size();
        std::vector<std::vector<int>> AREA(rowS, std::vector<int>(colS, 0));

        // start computing

        // the first row
        for (int i=0; i<colS; i++) {

            if (obstacleGrid[0][i] == 1) break;
            else AREA[0][i] = 1;

        }

        // the first column
        for (int i=0; i<rowS; i++) {

            if (obstacleGrid[i][0] == 1) break;
            else AREA[i][0] = 1;

        }

        // other areas
        for (int i=1; i<rowS; i++) {
            for (int j=1; j<colS; j++) {

                if (obstacleGrid[i][j] == 1) continue;
                else AREA[i][j] = AREA[i-1][j] + AREA[i][j-1];

            }
        }

        return AREA[rowS-1][colS-1];

    }
};
