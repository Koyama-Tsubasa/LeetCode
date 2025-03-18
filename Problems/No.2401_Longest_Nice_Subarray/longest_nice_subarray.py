class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        bit_used, lft_id, max_length = 0, 0, 0

        for rht_id, rht_num in enumerate(nums):
            while ((bit_used & rht_num) != 0):
                bit_used ^= nums[lft_id]
                lft_id += 1
            
            bit_used |= rht_num
            max_length = max(max_length, rht_id-lft_id+1)
        
        return max_length
