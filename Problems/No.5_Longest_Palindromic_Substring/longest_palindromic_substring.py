class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
          
        # Expanding Method:
        #   if s is "babad", l=2, r=2
        #   run1 ... b,     l=2, r=2
        #   run2 ... aba,   l=1, r=3
        #   run3 ... babad, l=0, r=4
        #   since s[0]=b != d=s[4] 
        #   return r-l-1 = 4-0-1 = 3 = len("aba")
        def EM(s, l, r):
            while (l>=0) and (r<len(s)) and (s[l] == s[r]):
                l -= 1
                r += 1
            return r-l-1
        
        # store the LPS's start point and end point
        LPS_start, LPS_end = 0, 0
        
        # start compute
        for i in range(len(s)):
            
            # compare the odd one and even one
            LPS_odd = EM(s, i, i)
            LPS_even = EM(s, i, i+1)
            max_LPS_len = max(LPS_odd, LPS_even)
            
            # update the LPS answer
            if (max_LPS_len > LPS_end-LPS_start):
                LPS_start = i - (max_LPS_len-1)//2
                LPS_end = i + max_LPS_len//2
                print(LPS_start, LPS_end)
            
        return s[LPS_start:LPS_end+1]
