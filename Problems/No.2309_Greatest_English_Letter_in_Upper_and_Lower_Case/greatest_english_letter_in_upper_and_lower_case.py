class Solution(object):
    def greatestLetter(self, s):
        """
        :type s: str
        :rtype: str
        """

        # parameter
        letter_set = set(s)

        # start computing
        upper, lower = ord('Z'), ord('z')
        for i in range(26):
            if ((chr(upper-i) in letter_set) and (chr(lower-i) in letter_set)):
                return chr(upper-i)
        
        return ""
