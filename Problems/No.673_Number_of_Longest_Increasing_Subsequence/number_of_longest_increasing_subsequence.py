class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameters
        LIS_len = [1] * len(nums)
        LIS_cnt = [1] * len(nums)
        MAX_LIS = 1
        MAX_LIS_cnt = 0

        # start computing
        for i in range(len(nums)):
            for j in range(i):
                if (nums[j] < nums[i]):
                    if (LIS_len[i] < (LIS_len[j] + 1)):
                        LIS_len[i] = LIS_len[j] + 1
                        LIS_cnt[i] = LIS_cnt[j]
                    elif (LIS_len[i] == (LIS_len[j] + 1)):
                        LIS_cnt[i] += LIS_cnt[j]
            MAX_LIS = max(MAX_LIS, LIS_len[i])

        for [lis_len, lis_cnt] in zip(LIS_len, LIS_cnt):
            if (lis_len == MAX_LIS):
                MAX_LIS_cnt += lis_cnt
        
        return MAX_LIS_cnt
