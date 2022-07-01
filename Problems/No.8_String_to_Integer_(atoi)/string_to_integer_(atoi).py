class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # store the answer and the flag or positive, negative
        StI_ans = ""
        pos_neg = None
        
        # start compute
        for c in s:
            if (c == ' ' and pos_neg == None and StI_ans == ""):
                continue
            elif (c == '+' and pos_neg == None and StI_ans == ""):
                pos_neg = 0
            elif (c == '-' and pos_neg == None and StI_ans == ""):
                pos_neg = 1
            elif (c.isdigit()):
                StI_ans += c
            else:
                break
        
        # check if the final value is legal
        try:
            final_value = int(StI_ans)
            return max(-final_value, -2**31) if pos_neg else min(final_value, 2**31-1)
        except:
            return 0
            
                
        
