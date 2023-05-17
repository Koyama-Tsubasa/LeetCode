class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """

        # parameters
        k_binary_codes = set()
        all_codes = 1<<k

        # start computing
        if (len(s) < k+all_codes-1):
            return False
        for i in range(len(s)-k+1):
            k_binary_codes.add(s[i:i+k])
        
        return True if (len(k_binary_codes) == all_codes) else False
