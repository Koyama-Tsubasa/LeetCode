class Solution(object):
    def distance(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # parameters
        num_count_sum = {}
        SoD = [0] * len(nums)

        # start computing
        # count the total sum and # of each num
        for i in range(len(nums)):
            if nums[i] not in num_count_sum:
                num_count_sum[nums[i]] = [1, i]
            else:
                num_count_sum[nums[i]][0] += 1
                num_count_sum[nums[i]][1] += i
        
        # calculate the distances
        partial_NCS = {}
        for i in range(len(nums)):
            num = nums[i]
            [total_count, total_sum] = num_count_sum[num]
            
            if num not in partial_NCS:
                partial_NCS[num] = [1, i]
            else:
                partial_NCS[num][0] += 1
                partial_NCS[num][1] += i
            [left_count, left_sum] = partial_NCS[num]
           
            # ans for index i will be i * leftSize - prefixSum of left side + prefixSum of right side - i * rightSize
            SoD[i] = i*(2*left_count - total_count) - (2*left_sum - total_sum)

        return SoD
