class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameters
        i = 0
        sizeN = len(nums)

        # start computing
        while (i < sizeN):
            if ((0 < nums[i]) and (nums[i] <= sizeN) and
                (nums[nums[i]-1] != nums[i])):
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
            else:
                i += 1

        for i in range(sizeN):
            if (nums[i] != i+1):
                return i+1
        return sizeN+1
