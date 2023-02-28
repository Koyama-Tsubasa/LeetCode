class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        # parameters
        cur, left, right = 0, 0, len(nums)-1

        # start computing (use Dutch National Flag algorithm)
        while (cur <= right):
            if (nums[cur] == 0):
                nums[cur], nums[left] = nums[left], nums[cur]
                left += 1
                cur += 1
            elif (nums[cur] == 1):
                cur += 1
            else:
                nums[cur], nums[right] = nums[right], nums[cur]
                right -= 1
