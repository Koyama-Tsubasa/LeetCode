class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        # parameters
        row = ""
        col = ["" for _ in range(9)]
        box = ["" for _ in range(3)]
        
        # start compute
        for i in range(9):
            for j in range(9):
                
                check_value = board[i][j]
                
                if (check_value != '.'):
                    
                    if (check_value in row or check_value in col[j] or check_value in box[j//3]):
                        return False
                    else:
                        
                        row += check_value
                        col[j] += check_value
                        box[j//3] += check_value
                        
            # reset some saving data
            row = ""
            if (i%3 == 2):
                for b in range(3):
                    box[b] = ""
                    
        return True
        
