class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
        # store the length
        len_haystack = len(haystack)
        len_needle = len(needle)
        
        # preprocess
        if (len_haystack < len_needle):
            return -1
        
        # start compute
        for i in range(len_haystack - len_needle + 1):
            if (haystack[i:i+len_needle] == needle):
                return i
        
        return -1
