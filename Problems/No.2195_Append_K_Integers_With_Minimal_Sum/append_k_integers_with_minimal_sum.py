class Solution(object):
    def minimalKSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        appended_sum = 0
        added_num = 0
        i = 1

        # start computing
        nums.sort()
        nums.insert(0, 0)
        
        while (k > 0):

            # the case between two nums
            added_num = nums[i] - nums[i-1] - 1
            if (added_num > 0):
                added_num = min(added_num, k)
                appended_sum += ((nums[i-1]+1) + (nums[i-1]+added_num))*added_num//2
                k -= added_num
            i += 1

            # the case after all nums
            if ((i >= len(nums)) and (k > 0)):
                appended_sum += ((nums[-1]+1) + (nums[-1]+k))*k//2
                break

        return appended_sum
