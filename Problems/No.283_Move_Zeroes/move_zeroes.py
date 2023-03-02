class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        # parameter
        pSwap = 0

        # start computing
        for i in range(len(nums)):
            if (nums[i] != 0):
                nums[pSwap], nums[i] = nums[i], nums[pSwap]
                pSwap += 1
