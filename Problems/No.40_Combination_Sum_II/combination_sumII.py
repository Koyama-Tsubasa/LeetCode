class Solution(object):
    def combinationSum2(self, candidates, target):
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
            elif target == 0:
                combinations.append(temp)
                return 
            for i in range(index, len(candidates)):
                
                # remove duplicate
                if (i>index and candidates[i]==candidates[i-1]):
                    continue
                backtracking(target-candidates[i], i+1, temp+[candidates[i]])
        
        # parameter
        combinations = []
        
        # start compute
        candidates.sort()
        backtracking(target, 0, [])
        
        return combinations
        
