class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        # whether x is negative or x except 0 is ten multiples or not
        if (x < 0 or (x%10 == 0 and x!=0)):
            return False
        else:
            x_original = x  # save the x
            x_reverse = 0   # calculate the reverse of x
            while (x_original!=0):
                x_reverse = x_reverse*10 + x_original%10
                x_original = x_original/10
            return x == x_reverse
