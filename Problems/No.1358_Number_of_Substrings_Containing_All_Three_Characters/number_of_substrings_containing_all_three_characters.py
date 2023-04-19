class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """

        # parameters
        count = 0
        sLen = len(s)
        char_count = {'a': 0, 'b': 0, 'c': 0}

        # start computing
        substr_start = 0
        for substr_end, c in enumerate(s):
            char_count[c] = char_count.get(c, 0) + 1
            while ((char_count['a'] > 0) and (char_count['b'] > 0) and (char_count['c'] > 0) and
                   (substr_start <= substr_end)):
                char_count[s[substr_start]] = char_count.get(s[substr_start], 0) - 1
                substr_start += 1
                count += sLen - substr_end

        return count
