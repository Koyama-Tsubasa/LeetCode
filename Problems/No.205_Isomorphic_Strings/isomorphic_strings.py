class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # start computing
        if (len(s) != len(t)):
            return False
        else:
            for i in range(len(s)):
                IDs = s.index(s[i])
                IDt = t.index(t[i])
                if (IDs != IDt):
                    return False
                else:
                    continue
            
        return True
