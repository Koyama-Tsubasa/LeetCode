class Solution(object):
    def maximumTop(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameter
        max_value = 0

        # start computing
        if ((len(nums) == 1) and (k%2 == 1)):
            return -1
        else:
            for i in range(min(len(nums), k-1)):
                max_value = max(max_value, nums[i])
            if (k < len(nums)):
                max_value = max(max_value, nums[k])
            return max_value
