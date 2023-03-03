class Solution {

private:
    
    // check if the word strings start from the current index contain the desired word
    bool checkBoard(std::vector<std::vector<char>> &board, std::string word, int row, int col, int checkP) {

        // parameters
        char checkWord;
        bool up, down, left, right;

        // start checking
        if (checkP == word.size()) return true;
        else if ((row < 0) || (col < 0) || (row >= board.size()) || (col >= board[0].size()) || (board[row][col] != word[checkP])) return false;

        checkWord = board[row][col];
        board[row][col] = ' ';
        up = checkBoard(board, word, row-1, col, checkP+1);
        down = checkBoard(board, word, row+1, col, checkP+1);
        left = checkBoard(board, word, row, col-1, checkP+1);
        right = checkBoard(board, word, row, col+1, checkP+1);
        board[row][col] = checkWord;
        
        return (up || down || left || right);

    }

public:
    bool exist(vector<vector<char>>& board, string word) {
       
        // start computing
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                if (checkBoard(board, word, i, j, 0))
                    return true;
        
        return false;

    }
};
