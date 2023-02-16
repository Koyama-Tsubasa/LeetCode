class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // parameters
        std::vector<int> spiral_order;
        int c_start = 0, r_start = 0;
        int c_end = matrix[0].size()-1;
        int r_end = matrix.size()-1;
        int Msize = (c_end+1)*(r_end+1);

        // start computing
        while(spiral_order.size() != Msize) {

            // Top Row
            for (int i=c_start; i<=c_end; i++) spiral_order.push_back(matrix[r_start][i]);

            // Right Column
            for (int i=r_start+1; i<=r_end; i++) spiral_order.push_back(matrix[i][c_end]);

            // Bottom Row
            if (r_start != r_end) 
                for (int i=c_end-1; i>=c_start; i--) 
                    spiral_order.push_back(matrix[r_end][i]);

            // Left Column
            if (c_start != c_end)
                for (int i=r_end-1; i>=r_start+1; i--) 
                    spiral_order.push_back(matrix[i][c_start]);

            // update parameters
            r_start++;
            c_start++;
            r_end--;
            c_end--;
            
        }

        return spiral_order;

    }
};
