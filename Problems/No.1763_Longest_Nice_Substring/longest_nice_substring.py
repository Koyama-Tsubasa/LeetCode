class Solution(object):
    def longestNiceSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """

        # parameter
        buddies = []

        # start computing
        # find buddies
        for c in s:
            if c.islower():
                buddies.append(c.upper())
            else:
                buddies.append(c.lower())
        
        # divide and conquer according to unfound buddies
        for i, c in enumerate(s):
            if c in buddies:
                continue
            left_substr = self.longestNiceSubstring(s[:i])
            right_substr = self.longestNiceSubstring(s[i+1:])
            return left_substr if (len(left_substr) >= len(right_substr)) else right_substr
        
        return s
        
