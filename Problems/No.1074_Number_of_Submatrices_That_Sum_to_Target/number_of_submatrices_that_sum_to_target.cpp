class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        // reference
        // https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/solutions/2298548/c-java-python-subarray-sum-explained/

        // parameters
        int target_count = 0;
        int row_num = matrix.size(), col_num = matrix[0].size();
        std::vector<std::vector<int>> preSum(row_num, std::vector<int>(col_num, 0));

        // start computing
        // first check for the initial condition
        if (row_num < 1) return 0;

        // calculate prefix sum for each row
        for (int row=0; row<row_num; row++) {

            int preSum_tempR = 0;
            for (int col=0; col<col_num; col++) {

                preSum_tempR += matrix[row][col];
                preSum[row][col] = preSum_tempR;

            }

        }       

        // check for matches
        int partial_sum;
        std::unordered_map<int, int> counter;
        for (int colS=0; colS<col_num; colS++) 
            for (int col=colS; col<col_num; col++) {

                counter = {{0, 1}};
                partial_sum = 0;
                for (int row=0; row<row_num; row++) {

                    partial_sum += preSum[row][col] - ((colS > 0) ? preSum[row][colS-1] : 0);
                    target_count += (counter.find(partial_sum - target) != counter.end()) ? counter[partial_sum - target] : 0;
                    counter[partial_sum] ++;

                }

            }
        
        return target_count;

    }
};
