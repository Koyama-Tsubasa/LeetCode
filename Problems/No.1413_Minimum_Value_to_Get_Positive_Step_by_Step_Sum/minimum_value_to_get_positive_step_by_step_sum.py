class Solution(object):
    def minStartValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameter
        min_sum = float('inf')

        # start computing
        num_sum = 0
        for num in nums:
            num_sum += num
            min_sum = min(min_sum, num_sum)
        
        return 1 if (min_sum > 0) else abs(min_sum)+1
