class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # parameters
        jumpIndex, maxJump, jump = 0, 0, 0
        i = 0
        
        # start compute
        while (jumpIndex < len(nums)-1):
            maxJump = max(maxJump, i+nums[i])
            if (i == jumpIndex):
                jumpIndex = maxJump
                jump += 1
            i += 1
                
        return jump
