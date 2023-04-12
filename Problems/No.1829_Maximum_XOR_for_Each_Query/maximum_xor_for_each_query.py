class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        """
        :type nums: List[int]
        :type maximumBit: int
        :rtype: List[int]
        """

        # parameters
        num_Size = len(nums)
        previous_xor = 0
        MAX_k = (1<<maximumBit) - 1
        MAX_XOR = [0] * num_Size

        # start computing
        for i in range(num_Size):
            previous_xor ^= nums[i]
            MAX_XOR[num_Size-i-1] = previous_xor ^ MAX_k
        
        return MAX_XOR
