class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        
        # Pow(x, n) for n>0
        def pos_pow(x, n):
            if (n == 1):
                return x
            else:
                if n%2:
                    return x*pos_pow(x, n-1)
                else:
                    return pos_pow(x*x, n//2)
        
        # Pow(x, n) for n<0
        def neg_pow(x, n):
            if (n == -1):
                return x
            else:
                if n%2:
                    return x*neg_pow(x, n+1)
                else:
                    return neg_pow(x*x, n//2)
        
        if not n:
            return 1
        else:
            if (n > 0):
                return pos_pow(x, n)
            else:
                return neg_pow(1/x, n)
