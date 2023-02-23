class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # check if it is negative or not
        if (n < 0):
            return False

        # convert into bitset and check if the number of 1 bit is only 1
        Tbits = format(n, "032b")
        return True if (Tbits.count("1") == 1) else False
