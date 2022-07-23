class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # parameter
        ans = 0
        
        # start compute
        # left to right but cannot check the patterns like "(()"
        open_bracket, close_bracket = 0, 0
        for c in s:
            if (c == '('):
                open_bracket += 1
            else:
                close_bracket += 1
            if (open_bracket == close_bracket):
                ans = max(ans, 2*open_bracket)
            elif (close_bracket > open_bracket):
                open_bracket = 0
                close_bracket = 0
        
        # right to left but cannot check the patterns like "())"
        open_bracket, close_bracket = 0, 0
        for c in s[::-1]:
            if (c == ')'):
                close_bracket += 1
            else:
                open_bracket += 1
            if (open_bracket == close_bracket):
                ans = max(ans, 2*close_bracket)
            elif (close_bracket < open_bracket):
                open_bracket = 0
                close_bracket = 0
        
        return ans
