class Solution(object):
    def maxSubarraySumCircular(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # reference:
        # https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/3068804/kadane-min-sum-subarray/

        # parameters
        global_MAX, global_min = nums[0], nums[0]
        local_MAX, local_min = 0, 0
        total_sum = 0

        # start computing (using modified Kadane's Algorithm)
        for num in nums:
            total_sum += num

            local_MAX = max(local_MAX + num, num)
            local_min = min(local_min + num, num)

            global_MAX = max(global_MAX, local_MAX)
            global_min = min(global_min, local_min)
        
        return max(global_MAX, total_sum - global_min) if (global_MAX > 0) else global_MAX
        
