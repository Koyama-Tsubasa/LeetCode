class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameters
        num_sum, left_sum = 0, 0
        
        # start computing
        for num in nums:
            num_sum += num
        for pivot_idx, num in enumerate(nums):
            num_sum -= num
            if (num_sum == left_sum):
                return pivot_idx
            else:
                left_sum += num
        
        return -1
