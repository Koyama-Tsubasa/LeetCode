class Solution(object):
    def minimumDifference(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameter
        min_gap = float('inf')

        # start computing
        nums.sort()
        for i in range(len(nums)-k+1):
            min_gap = min(min_gap, nums[i+k-1]-nums[i])
        
        return min_gap
