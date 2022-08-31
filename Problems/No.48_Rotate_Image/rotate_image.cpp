class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // parameters
        int size = matrix.size();
        int r_num = size - 1;
        int temp;
        
        // start compute
        for (int i=0; i<size/2; i++) {
            
            for (int j=0; j<r_num; j++) {
                
                // do swapping between four numbers
                temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[size-1-i-j][i];
                matrix[size-1-i-j][i] =  matrix[size-1-i][size-1-i-j];
                matrix[size-1-i][size-1-i-j] = matrix[i+j][size-1-i];
                matrix[i+j][size-1-i] = temp;
                
            }
            r_num -= 2;
            
        }
        
        return;
        
    }
};
