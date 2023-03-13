class Solution(object):
    def minimumSum(self, num):
        """
        :type num: int
        :rtype: int
        """

        # parameter
        digits = []

        # start computing
        for i in range(4):
            digits.append(num%10)
            num //= 10
        digits.sort()

        return ((digits[0]+digits[1])*10 + digits[2] + digits[3])
