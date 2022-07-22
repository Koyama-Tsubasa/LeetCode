class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        
        # parameter
        ans = [1]
        
        # start compute
        for i in range(rowIndex):
            ans.append(1)
            for j in range(i, 0, -1):
                ans[j] += ans[j-1]
        
        return ans
        
