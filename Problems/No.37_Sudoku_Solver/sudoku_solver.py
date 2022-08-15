class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        
        # check if the num in valid in this position
        def safe(board, row, col, c):
            
            # parameters
            block_row = row - row%3
            block_col = col - col%3
            
            # start checking
            for i in range(9):
                if (board[row][i]==c or board[i][col]==c):
                    return False
            for i in range(3):
                for j in range(3):
                    if (board[block_row+i][block_col+j] == c):
                        return False
            
            return True
    
        # sudoku solver using back propagating
        def SudokuSolver(board):
            
            # parameters
            nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
            check_if_ans = True
            
            # start compute
            for row in range(9):
                for col in range(9):
                    if (board[row][col] == '.'):
                        
                        # start check with each valid num
                        for c in nums:
                            if (safe(board, row, col, c)):
                                board[row][col] = c
                                check_if_ans = SudokuSolver(board)
                                
                                # verify if the sudoku is solved
                                if (check_if_ans):
                                    return True
                                else:
                                    board[row][col] = '.'
                        return False
            return True
        
        SudokuSolver(board)
