class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        temp_sum, MAX_sum = 0, 0
        distinct_num_count = {}

        # start computing
        for i in range(len(nums)):
            distinct_num_count[nums[i]] = distinct_num_count.get(nums[i], 0) + 1
            temp_sum += nums[i]

            if (i < k-1):
                continue
            else:
                if (len(distinct_num_count) == k):
                    MAX_sum = max(MAX_sum, temp_sum)
                
                substract = nums[i-k+1]
                temp_sum -= substract

                if (distinct_num_count[substract] == 1):
                    del distinct_num_count[substract]
                else:
                    distinct_num_count[substract] -= 1
        
        return MAX_sum
