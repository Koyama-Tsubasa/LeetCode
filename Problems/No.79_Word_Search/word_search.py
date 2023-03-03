class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """

        # check if the word strings start from the current index contain the desired word
        def checkBoard(row, col, checkP):

            # parameters
            checkWord = None
            up, down, left, right = None, None, None, None
        
            # start computing
            if (checkP == len(word)):
                return True
            elif ((row < 0) or (col < 0) or (row >= len(board)) or (col >= len(board[0])) or board[row][col] != word[checkP]):
                return False
            
            checkWord = board[row][col]
            board[row][col] = ' '
            up = checkBoard(row-1, col, checkP+1)
            down = checkBoard(row+1, col, checkP+1)
            left = checkBoard(row, col-1, checkP+1)
            right = checkBoard(row, col+1, checkP+1)
            board[row][col] = checkWord

            return (up or down or left or right)
        
        # start computing
        for i in range(len(board)):
            for j in range(len(board[0])):
                if checkBoard(i, j, 0):
                    return True
        
        return False
