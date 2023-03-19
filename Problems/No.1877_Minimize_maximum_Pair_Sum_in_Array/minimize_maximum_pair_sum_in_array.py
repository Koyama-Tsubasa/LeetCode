class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameter
        max_PS = 0
        i, j = 0, len(nums)-1

        # start computing
        nums.sort()
        while (i < j):
            max_PS = max(max_PS, nums[i]+nums[j])
            i += 1
            j -= 1
        
        return max_PS
