class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameter
        numSet = []

        # start computing
        for num in nums:
            if ((num > 0) and (num not in numSet)):
                numSet.append(num)

        return len(numSet)
