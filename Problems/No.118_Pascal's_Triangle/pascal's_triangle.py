class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        
        # parameter
        ans = []
        
        # start compute
        for i in range(numRows):
            
            ans.append([])
            for j in range(i):
                if (j == 0):
                    ans[i].append(1)
                else:
                    ans[i].append(ans[i-1][j-1]+ans[i-1][j])
            ans[i].append(1)
        
        return ans
        
