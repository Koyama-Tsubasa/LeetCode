class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # parameter
        ans = 0

        # start computing
        # reference: https://reurl.cc/n7OAXv
        for num in nums:
            if (ans < 2):
                ans += 1
            elif (nums[ans-2] < num):
                nums[ans] = num
                ans += 1

        return ans
