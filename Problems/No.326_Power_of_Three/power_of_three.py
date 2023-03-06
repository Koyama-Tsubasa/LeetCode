class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # start computing
        if (n <= 0):
            return False
        else:
            power = math.log10(n)/math.log10(3)
            return (int(power) == power)
