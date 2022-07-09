class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        # store some parameters
        AB_ans = ""
        len_a, len_b = len(a) - 1, len(b) - 1
        carry = 0
        
        # start compute
        while (len_a >= 0 or len_b >= 0 or carry):
            
            if (len_a >= 0 and a[len_a] == '1'):
                carry += 1
            if (len_b >= 0 and b[len_b] == '1'):
                carry += 1
            AB_ans = str(carry % 2) + AB_ans;
            carry //= 2
            
            len_a -= 1
            len_b -= 1
        
        return AB_ans
            
