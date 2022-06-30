class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        
        # store the maximum movement 
        max_move = 2*(numRows-1)
        ZC_ans = ""
        
        # start compute
        if (numRows == 1):
            return s
        else:
            
            '''
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
            '''
            for i in range(numRows):
                
                cur_index = i
                cur_move = 2*(numRows-1) - 2*(i%(numRows-1))
                
                while (cur_index < len(s)):
                    
                    ZC_ans += s[cur_index]
                    cur_index += cur_move
                    if (cur_move != max_move):
                        cur_move = max_move - cur_move
        
        return ZC_ans
