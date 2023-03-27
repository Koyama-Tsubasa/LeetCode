class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # start computing
        nums.sort()

        return ((nums[-1]-1) * (nums[-2]-1))
