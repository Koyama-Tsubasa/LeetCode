class Solution(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """

        # parameters
        dis_cnt = 0
        dis_subarrays = set()

        # start computing
        for i in range(len(nums)):
            divisible = 0
            subarray = ""
            for j in range(i, len(nums)):
                if (nums[j]%p == 0):
                    divisible += 1
                if (divisible > k):
                    break
                subarray += (str(nums[j]) + "-")
                if subarray not in dis_subarrays:
                    dis_cnt += 1
                    dis_subarrays.add(subarray)
        
        return dis_cnt
