class Solution {
public:

    // check if it is zero matrix
    bool CheckZero(vector<vector<int>>& matrix) {

        for (int i=0; i<matrix.size(); i++) 
            for (int j=0; j<matrix[0].size(); j++) 
                if (matrix[i][j] == 1) return false;
        
        return true;

    }

    int minFlips(vector<vector<int>>& mat) {
        
        // parameters
        std::queue<std::vector<std::vector<int>>> AllPossibles;
        std::set<std::vector<std::vector<int>>> checked; 
        std::vector<std::pair<int, int>> checks = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int flip_count = 0;
        int m = mat.size(), n = mat[0].size();

        // start computing
        AllPossibles.push(mat);
        checked.insert(mat);
        while (!AllPossibles.empty()) {
            
            int CheckSize = AllPossibles.size();
            for (int i=0; i<CheckSize; i++) {
                
                if (CheckZero(AllPossibles.front())) return flip_count;
                else {

                    for (int row=0; row<m; row++) {
                        for (int col=0; col<n; col++) {

                            auto currMat = AllPossibles.front();
                            currMat[row][col] = 1 - currMat[row][col];

                            for (auto check: checks) {

                                int newRow = row + check.first;
                                int newCol = col + check.second;
                                if ((0 <= newRow) && (newRow < m) && (0 <= newCol) && (newCol < n))
                                    currMat[newRow][newCol] = 1 - currMat[newRow][newCol];

                            }
                            
                            if (checked.find(currMat) == checked.end()) {

                                AllPossibles.push(currMat);
                                checked.insert(currMat);

                            }

                        }
                    }
                    AllPossibles.pop();

                }

            }
            flip_count++;

        }

        return -1;

    }
};
