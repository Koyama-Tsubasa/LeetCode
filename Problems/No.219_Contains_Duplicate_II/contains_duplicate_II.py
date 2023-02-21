class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        # parameter
        Nmapping = {}

        # start computing
        for i in range(len(nums)):
            if ((Nmapping.get(nums[i]) != None) and (i-Nmapping.get(nums[i]) <= k)):
                return True
            Nmapping[nums[i]] = i

        return False
