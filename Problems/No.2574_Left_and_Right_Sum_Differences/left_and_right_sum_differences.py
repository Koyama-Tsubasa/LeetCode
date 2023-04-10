class Solution(object):
    def leftRigthDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # parameter
        LRDifference = [0]

        # start computing
        for num in nums:
            LRDifference.append(LRDifference[-1] + num)
        for i in range(len(nums)):
            LRDifference[i] = abs(LRDifference[-1] - LRDifference[i+1] - LRDifference[i])
        LRDifference.pop()
        
        return LRDifference
