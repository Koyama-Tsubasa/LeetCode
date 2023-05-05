class Solution(object):
    def commonFactors(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """

        # parameter
        CF_cnt = 1
    
        # start computing
        for i in range(2, min(a, b)+1):
            if ((a%i == 0) and (b%i == 0)):
                CF_cnt += 1
        
        return CF_cnt
