class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        # find all permutations using backtracking
        def solve(nums, permutation):
            if (len(permutation) == length):
                all_permutations.append(permutation)
            for i in range(len(nums)):
                solve(nums[:i]+nums[i+1:], permutation + [nums[i]])
                
        # parameters
        all_permutations = []  
        length = len(nums)
        
        # start compute
        solve (nums, [])
        return all_permutations
