class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        # dynamic programming
        # T(n) = T(n-1) + T(n-2)
        # T(1) = 1, T(2) = 2, T(3) = 3
        
        # start compute
        if (n < 4):
            return n;
        else:
            
            # initialize T(n-1) = T(3), T(n-2) = T(2)
            T_1 = 3;
            T_2 = 2;
            
            # iterate
            for i in range(n-4):
                
                temp = T_1
                T_1 += T_2
                T_2 = temp
            
        return T_1+T_2
        
