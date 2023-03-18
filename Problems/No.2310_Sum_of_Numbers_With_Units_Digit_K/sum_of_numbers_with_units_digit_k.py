class Solution(object):
    def minimumNumbers(self, num, k):
        """
        :type num: int
        :type k: int
        :rtype: int
        """

        # start computing
        if (num == 0):
            return 0
        else:
            for minSize in range(1, 11):
                if (((minSize*k % 10) == (num % 10)) and (minSize*k <= num)):
                    return minSize
            return -1
