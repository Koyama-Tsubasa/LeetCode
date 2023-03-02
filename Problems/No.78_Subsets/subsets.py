class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        # create subsets under corresponding size
        def create_subsets(start, size):
            if (len(subset) == size):
                subset_copy = subset[:]
                subsets.append(subset_copy)
            else:
                for i in range(start, len(nums)):
                    subset.append(nums[i])
                    create_subsets(i+1, size)
                    subset.pop()

        # parameters
        subsets, subset = [], []

        # start computing
        subsets.append([])
        for i in range(1, len(nums)+1):
            create_subsets(0, i)
            subset = []

        return subsets
