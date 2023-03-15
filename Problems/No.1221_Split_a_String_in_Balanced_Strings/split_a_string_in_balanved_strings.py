class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """

        # parameter
        balanced = 0
        balanced_strings = 0
    
        # start computing
        for c in s:
            if (c == 'L'):
                balanced += 1
            else:
                balanced -= 1
            if (balanced == 0):
                balanced_strings += 1
        
        return balanced_strings
