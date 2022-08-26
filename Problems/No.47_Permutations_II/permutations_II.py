class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        # find all permutations using backtracking
        def solve(nums, permutation):
            # check if it duplicates
            if ((len(permutation)==length) and (permutation not in all_permutations)):
                all_permutations.append(permutation)
            for i in range(len(nums)):
                solve(nums[:i]+nums[i+1:], permutation + [nums[i]])
                
        # parameters
        all_permutations = []  
        length = len(nums)
        
        # start compute
        nums.sort()
        solve (nums, [])
        return all_permutations
