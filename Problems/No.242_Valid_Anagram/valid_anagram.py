class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # parameter
        alphaTable = [0]*26

        # start computing
        if (len(s) != len(t)):
            return False
        
        for i in range(len(s)):
            alphaTable[ord(s[i])-ord('a')] += 1
            alphaTable[ord(t[i])-ord('a')] -= 1
        
        for i in range(26):
            if alphaTable[i]:
                return False

        return True
