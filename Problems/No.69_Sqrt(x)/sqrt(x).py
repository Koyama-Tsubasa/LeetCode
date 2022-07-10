class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        # store some parameters
        left, right, mid = 0, x, None
        square = None
        sqrt_ans = None
        
        # start compute (BinarySearch method)
        while (left <= right):
            
            mid = (left+right)//2
            square = mid * mid;
            
            if (square == x):
                return mid
            elif (square > x):
                right = mid - 1
            else:
                left = mid + 1
                sqrt_ans = mid
            
        return sqrt_ans
