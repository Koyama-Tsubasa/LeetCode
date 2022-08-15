class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        # parameters
        front, end = 0, len(s)-1
        
        # start compute
        while (front < end):
            if (not s[front].isalnum()):
                front += 1
            elif (not s[end].isalnum()):
                end -= 1
            elif (s[front].lower() != s[end].lower()):
                return False
            else:
                front += 1
                end -= 1
        
        return True
        
