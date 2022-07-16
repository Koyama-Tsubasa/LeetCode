class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // parameters, using three vector<set> to save previous checking
        vector<set<char>> row(9), column(9), box(9);
        char check_value;
        int box_index;
        
        // start compute
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                
                check_value = board[i][j];
                
                if (check_value != '.'){
                    
                    box_index = i/3*3 + j/3;
                    
                    if (row[i].find(check_value)!=row[i].end() or 
                        column[j].find(check_value)!=column[j].end() or
                        box[box_index].find(check_value)!=box[box_index].end()) return false;
                    else {
                        
                        row[i].insert(check_value);
                        column[j].insert(check_value);
                        box[box_index].insert(check_value);
                        
                    }
                    
                }
                
            }
        }
        
        return true;
        
    }
};
