class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        
        # start compute
        while (val in nums):
            nums.remove(val)
            
        return len(nums)
