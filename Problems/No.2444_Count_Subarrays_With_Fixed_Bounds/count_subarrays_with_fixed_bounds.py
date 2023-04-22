class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """

        # parameters
        min_found, MAX_found = -1, -1
        subarray_start = 0
        SubArrayCount = 0

        # start computing
        for i, num in enumerate(nums):
            if ((num < minK) or (num > maxK)):
                subarray_start = i + 1
                min_found = MAX_found = -1
            else:
                if (num == minK):
                    min_found = i
                if (num == maxK):
                    MAX_found = i
                if ((min_found > -1) and (MAX_found > -1)):
                    SubArrayCount += min(min_found, MAX_found) - subarray_start + 1
        
        return SubArrayCount
