class Solution {
public:
    
    // check if the num in valid in this position
    bool safe(vector<vector<char>> &board, int row, int col, char c) {
        
        // parameters
        int block_row = (row/3)*3;
        int block_col = (col/3)*3;
        
        // start checking
        for (int i=0; i<9; i++) if (board[i][col]==c or board[row][i]==c) return false;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++) 
                if (board[block_row+i][block_col+j] == c) return false;
        
        return true;
        
    }
    
    // sudoku solver using back propagating
    bool SudokuSolver(vector<vector<char>> &board) {
        
        // parameter
        bool check_if_solved;

        // start compute
        for (int row=0; row<9; row++) {
            for (int col=0; col<9; col++) {

                if (board[row][col]=='.') {

                    // start check with each valid num
                    for (char c='1'; c<='9'; c++) {
                        
                        if (safe(board,row,col,c)) {
                            
                            board[row][col]=c;
                            check_if_solved = SudokuSolver(board);

                            // verify if the sudoku is solved
                            if (check_if_solved) return true;
                            else board[row][col]='.';
                            
                        }
                        
                    }
                    
                    return false;
                    
                }
                
            }
        }
        
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        SudokuSolver(board);
        
    }
    
};
