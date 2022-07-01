class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        # store the answer and the input value used to compute
        RI_ans = 0
        compute_x = x if (x >= 0) else -x
        
        # start compute
        while (compute_x != 0):
            
            temp = compute_x%10
            
            # check if it overflow
            if ((RI_ans > 214748364) or
               ((RI_ans == 214748364) and (temp >= 7))):
                return 0
            else:
                RI_ans = RI_ans*10 + temp
            
            compute_x /= 10
        
        return RI_ans if (x >= 0) else -RI_ans
