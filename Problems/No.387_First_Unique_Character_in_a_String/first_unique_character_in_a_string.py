class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        # parameter
        char_count = {}

        # start computing
        for c in s:
            char_count[c] = char_count.get(c, 0) + 1
        for idx, c in enumerate(s):
            if (char_count[c] == 1):
                return idx
        
        return -1
