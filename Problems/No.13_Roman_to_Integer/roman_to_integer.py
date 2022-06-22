class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # construct Roman table
        Roman_table = {
            "I": 1, 
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        cur = 0     # save current partial Roman integer
        pre = 0     # save previous partial Roman integer
        output = 0  # calculate the output
        
        # start compute
        for sub_s in s:
            cur = Roman_table[sub_s]
            
            # check whether the subtraction is used or not
            if pre < cur:
                output = output - 2*pre + cur
            else:
                output = output + cur
            pre = cur
        
        return output
       
