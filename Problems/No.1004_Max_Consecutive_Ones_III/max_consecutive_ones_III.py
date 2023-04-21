class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        max_ones = 0
        start_idx = 0

        # start computing
        for end_idx in range(len(nums)):
            if (nums[end_idx] == 0):
                k -= 1
            while (k < 0):
                if (nums[start_idx] == 0):
                    k += 1
                start_idx += 1
            max_ones = max(max_ones, end_idx - start_idx + 1)
        
        return max_ones
