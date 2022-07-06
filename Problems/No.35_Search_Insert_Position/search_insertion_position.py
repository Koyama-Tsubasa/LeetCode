class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        SIP_ans = 0
        
        while (SIP_ans < len(nums)):
            if (nums[SIP_ans] >= target):
                return SIP_ans
            else:
                SIP_ans += 1
            
        return SIP_ans
