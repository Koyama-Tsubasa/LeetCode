class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // parameters
        int rowS = matrix.size();
        int colS = matrix[0].size();
        bool rFlag = false, cFlag = false;

        // start computing

        // search the first row & the first column
        for (int i=0; i<colS; i++) 
            if (matrix[0][i] == 0) {

                rFlag = true;
                break;

            }
        for (int i=0; i<rowS; i++) 
            if (matrix[i][0] == 0) {

                cFlag = true;
                break;

            }

        // search for others and convert the corresponding element in the 1st row&column to 0
        for (int i=1; i<rowS; i++)
            for (int j=1; j<colS; j++)
                if (matrix[i][j] == 0) 
                    matrix[i][0] = matrix[0][j] = 0;

        // update the zeros correspond to the inside area
        for (int i=1; i<rowS; i++)
            for (int j=1; j<colS; j++)
                if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
                    matrix[i][j] = 0;

        // update the the zeros correspond to the outside area
        if (rFlag == true) for (int i=0; i<colS; i++) matrix[0][i] = 0;
        if (cFlag == true) for (int i=0; i<rowS; i++) matrix[i][0] = 0;

    }
};
