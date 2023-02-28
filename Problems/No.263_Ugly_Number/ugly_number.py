class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # start computing
        if (n <= 0):
            return False
        for div in [2, 3, 5]:
            while (n%div == 0):
                n //= div
        
        return (n == 1)
