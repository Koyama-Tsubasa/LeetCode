class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        subarray_start = -1
        odd_IDs = []
        nice_count = 0

        # start computing
        for i in range(len(nums)):
            if (nums[i]%2 == 1):
                odd_IDs.append(i)
            if (len(odd_IDs) == k):
                nice_count += odd_IDs[0] - subarray_start
            elif (len(odd_IDs) > k):
                subarray_start = odd_IDs.pop(0)
                nice_count += odd_IDs[0] - subarray_start
        
        return nice_count
