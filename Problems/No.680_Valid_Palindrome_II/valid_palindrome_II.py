class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        # palindrome chance of deleting one character
        def PalindromeChance(L, R):
            while (L < R):
                if (s[L] == s[R]):
                    L += 1
                    R -= 1
                else:
                    return False
            return True
        

        # parameters
        pLeft, pRight = 0, len(s)-1
    
        # start computing
        while (pLeft < pRight):
            if (s[pLeft] == s[pRight]):
                pLeft += 1
                pRight -= 1
            else:
                return (PalindromeChance(pLeft+1, pRight) or PalindromeChance(pLeft, pRight-1))
        
        return True
