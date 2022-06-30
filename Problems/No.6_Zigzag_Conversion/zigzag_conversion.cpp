class Solution {
public:
    string convert(string s, int numRows) {
        
        // store the current index in the s, current movement, and maximum movement
        int cur_index;
        int cur_move;
        int max_move = 2*(numRows-1);
        string ZC_ans = "";
        
        // start compute
        if (numRows == 1) return s;
        else {
            
            /*
                ex (numRows = 5):
                
                    [index]
                    0       8           16 ...
                    1     7 9        15 17 ...
                    2   6   10    14    18 ...
                    3 5     11 13       19 ...
                    4       12          20 ...
                    
                    [movements]
                    row 1: +8, +8, ...
                    row 2: +6, +2, +6, +2, ...
                    row 3: +4, +4, +4, +4, ...
                    row 4: +2, +6, +2, +6, ...
                    row 5: +8, +8, ...
            */
            for (int i=0; i<numRows; i++) {
            
                cur_index = i;
                cur_move = max_move - 2*(i%(numRows-1));

                while (cur_index<s.length()) {

                    ZC_ans += s[cur_index];
                    cur_index += cur_move;
                    cur_move = (cur_move != max_move) ? max_move-cur_move : cur_move;
                    
                }

            }   
            
        }
        
        return ZC_ans;
        
    }
};
