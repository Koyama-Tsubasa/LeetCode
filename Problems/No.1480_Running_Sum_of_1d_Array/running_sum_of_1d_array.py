class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # parameter
        Rsum = 0
        Running_Sum = []

        # start computing
        for num in nums:
            Rsum += num
            Running_Sum.append(Rsum)
        
        return Running_Sum
