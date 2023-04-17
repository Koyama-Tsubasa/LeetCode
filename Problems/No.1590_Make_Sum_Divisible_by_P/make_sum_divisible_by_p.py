class Solution(object):
    def minSubarray(self, nums, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """

        # parameters
        subarray_size = len(nums)
        remainder = 0
        preSum_index = {}

        # start computing
        # check the remainder (need to remove)
        remainder = sum(nums) % p
        if (remainder == 0):
            return 0
        else:
            pre_sum, find_gap = 0, 0
            preSum_index[0] = -1
            for i, num in enumerate(nums):
                # calculate prefix sum with %p & save the index
                pre_sum = (pre_sum + num) % p
                preSum_index[pre_sum] = i

                # find if the gap between the current prefix sum and the target remainder exist
                find_gap = (pre_sum - remainder + p) % p
                if find_gap in preSum_index:
                    subarray_size = min(subarray_size, i-preSum_index[find_gap])

            return subarray_size if (subarray_size < len(nums)) else -1
