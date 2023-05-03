class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # start computing
        if (n == 1):
            return True
        
        n_str = list(str(n))
        n_str.sort()

        curr_p2 = 1
        for i in range(1, 32):
            curr_p2 <<= 1
            curr_p = list(str(curr_p2))
            curr_p.sort()
            if (n_str == curr_p):
                return True
        
        return False
