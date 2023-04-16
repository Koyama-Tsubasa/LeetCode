class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """

        # parameters
        num_sum = (1+n)*n//2
        check_pivot = 0

        # start computing
        for i in reversed(range(1, n+1)):
            check_pivot += i
            if (check_pivot == num_sum):
                return i
            num_sum -= i
        
        return -1
