class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // parameter
        std::vector<std::vector<int>> spiral_matrix(n, std::vector<int>(n, 0));
        int c_start = 0, r_start = 0, c_end = n-1, r_end = n-1;
        int count = 1;

        // start computing
        while (count <= n*n) {

            // Top Row
            for (int i=c_start; i<=c_end; i++) spiral_matrix[r_start][i] = count++;

            // Right Column
            for (int i=r_start+1; i<=r_end; i++) spiral_matrix[i][c_end] = count++;

            // Bottom Row
            for (int i=c_end-1; i>=c_start; i--) spiral_matrix[r_end][i] = count++;

            // Left Column
            for (int i=r_end-1; i>=r_start+1; i--) spiral_matrix[i][c_start] = count++;

            // update parameters
            r_start++;
            c_start++;
            r_end--;
            c_end--;

        }

        return spiral_matrix;

    }
};
