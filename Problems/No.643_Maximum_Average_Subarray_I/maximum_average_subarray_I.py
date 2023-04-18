class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """

        # parameters
        max_sum, partial_sum = -float('inf'), 0.0

        # start computing
        for i in range(len(nums)):
            partial_sum += nums[i]
            if (i < k-1):
                continue
            
            max_sum = max(max_sum, partial_sum)
            partial_sum -= nums[i-k+1]
        
        return max_sum/k
