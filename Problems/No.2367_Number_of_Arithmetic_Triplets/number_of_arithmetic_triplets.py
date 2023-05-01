class Solution(object):
    def arithmeticTriplets(self, nums, diff):
        """
        :type nums: List[int]
        :type diff: int
        :rtype: int
        """

        # parameters
        count = 0
        num_size = len(nums)

        # start computing
        for i in range(num_size):
            j = i + 1
            k = num_size - 1
            while (j < k):
                ij_diff = nums[j] - nums[i]
                jk_diff = nums[k] - nums[j]
                if (ij_diff == diff):
                    if (jk_diff == diff):
                        count += 1
                        break
                    elif (jk_diff < diff):
                        break
                    else:
                        k -= 1
                elif (ij_diff > diff):
                    break
                else:
                    j += 1
        
        return count
