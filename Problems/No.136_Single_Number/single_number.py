class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # parameter
        ans = 0
        
        # start compute, using XOR
        for num in nums:
            ans ^= num
        
        return ans
        
