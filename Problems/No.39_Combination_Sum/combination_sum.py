class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        # solve by backtracking
        def backtracking(target, index, temp):
            
            # check for each case
            if target < 0:
                return
            if target == 0:
                combinations.append(temp)
                return 
            for i in range(index, len(candidates)):
                backtracking(target-candidates[i], i, temp+[candidates[i]])
        
        # parameter
        combinations = []
        
        # start compute
        backtracking(target, 0, [])
        
        return combinations
        
