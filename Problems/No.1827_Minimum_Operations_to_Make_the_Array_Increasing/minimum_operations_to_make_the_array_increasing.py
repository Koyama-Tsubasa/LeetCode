class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameter
        operations = 0

        # start computing
        for i in range(1, len(nums)):
            if (nums[i-1] >= nums[i]):
                operations += (nums[i-1] - nums[i] + 1)
                nums[i] = nums[i-1] + 1
        
        return operations
