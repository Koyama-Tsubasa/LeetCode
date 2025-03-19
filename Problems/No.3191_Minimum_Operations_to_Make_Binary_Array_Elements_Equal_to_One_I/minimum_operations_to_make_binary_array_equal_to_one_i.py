class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        flip_cnt, nums_size = 0, len(nums)

        for i, num in enumerate(nums):
            if num == 1:
                continue
            if (i+2) >= len(nums):
                return -1
            nums[i+1] ^= 1
            nums[i+2] ^= 1
            flip_cnt += 1

        return flip_cnt
