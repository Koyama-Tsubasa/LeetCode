class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        # parameters
        Mstep = 0
        sizeN = len(nums)

        # start computing
        for i in range(sizeN):
            if ((i > Mstep) or (Mstep >= sizeN-1)):
                break
            else:
                Mstep = max(Mstep, i+nums[i])
        
        return True if (Mstep >= sizeN-1) else False
