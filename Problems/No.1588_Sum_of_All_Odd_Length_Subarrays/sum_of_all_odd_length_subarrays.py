class Solution(object):
    def sumOddLengthSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """

        # parameters
        arr_size = len(arr)
        preSum = [0] * arr_size

        # start computing
        # calculate prefix sum
        preSum[0] = arr[0]
        for i in range(1, arr_size):
            preSum[i] = preSum[i-1] + arr[i]

        # calculate the sum of subarrays from array size 3 (3, 5, 7, ...)
        OLS_sum = preSum[-1]
        for odd in range(2, arr_size, 2):
            OLS_sum += preSum[odd]
            for i in range(odd+1, arr_size):
                OLS_sum += preSum[i] - preSum[i-odd-1]

        return OLS_sum
