class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """

        # parameters
        strings = s.split()
        pattern_mapping = {}

        # start computing
        if (len(pattern) != len(strings)):
            return False
        else:
            for i in range(len(pattern)):
                if pattern[i] in pattern_mapping:
                    if pattern_mapping[pattern[i]] != strings[i]:
                        return False
                else:
                    if strings[i] in pattern_mapping.values():
                        return False
                    else:
                        pattern_mapping[pattern[i]] = strings[i]
        
        return True
