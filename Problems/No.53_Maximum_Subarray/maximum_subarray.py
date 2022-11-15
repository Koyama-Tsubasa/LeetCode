class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # parameters
        MAX = nums[0]   # store the maximum subarray value
        r = nums[0]     # store the contiguous maximal subarray value

        # start compute
        for i in range(1, len(nums)):

            # calculate the partial maximal sum (max{nums[i], r+nums[i]})
            if (r+nums[i] < nums[i]):
                r = nums[i]
            else:
                r += nums[i]

            # update the maximum sum
            if (r > MAX):
                MAX = r

        return MAX
