class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        # parameter
        binaryBits = [0]*(n+1)

        # start computing
        for i in range(1, n+1):
            binaryBits[i] = binaryBits[i//2] + i%2
        
        return binaryBits
