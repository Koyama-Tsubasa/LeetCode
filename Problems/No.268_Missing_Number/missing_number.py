class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameters
        numS = len(nums)
        missingN = (1+numS)*numS/2

        # start computing
        for num in nums:
            missingN -= num

        return missingN
