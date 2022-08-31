class Solution(object):
    def convertToTitle(self, columnNumber):
        """
        :type columnNumber: int
        :rtype: str
        """
        
        # parameters
        mapping = ['A', 'B', 'C', 'D', 'E',
                   'F', 'G', 'H', 'I', 'J',
                   'K', 'L', 'M', 'N', 'O',
                   'P', 'Q', 'R', 'S', 'T',
                   'U', 'V', 'W', 'X', 'Y', 'Z']
        ans = ""
        
        # start compute
        columnNumber -= 1
        while (columnNumber >= 0):
            ans = mapping[columnNumber%26] + ans;
            columnNumber //= 26
            columnNumber -= 1
        
        return ans
