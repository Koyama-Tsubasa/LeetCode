class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        # parameter
        num_set = set()

        # start computing
        for num in nums:
            if num in num_set:
                return True
            else:
                num_set.add(num)
        
        return False
