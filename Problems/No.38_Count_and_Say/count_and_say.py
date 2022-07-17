class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        # parameters
        i, cnt = 0, None
        s, CaS_ans = "", ""
        
        # start compute
        if (n == 1):
            return "1"
        else:
            
            # first return the previous answer
            s = self.countAndSay(n-1)
            
            while (i < len(s)):
            
                cnt = 1
                while (i<len(s)-1 and s[i]==s[i+1]):
                    i += 1
                    cnt += 1
                CaS_ans += str(cnt) + s[i]
                i += 1
                
        return CaS_ans
        
