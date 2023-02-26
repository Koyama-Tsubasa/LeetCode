class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // parameters
        int rowS = matrix.size(), colS = matrix[0].size();
        int left = 0, right = rowS*colS-1, mid;
        int r, c;

        // start computing (use Binary Search)
        while (left <= right) {

            mid = left + (right - left)/2;
            r = mid / colS;
            c = mid % colS;
            
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) left = mid + 1;
            else right = mid - 1;

        }

        return false;

    }
};
