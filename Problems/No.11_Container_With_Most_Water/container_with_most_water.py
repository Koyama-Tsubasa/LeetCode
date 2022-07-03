class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        # store answer and the pointers
        CWMW_ans = 0
        local_ans = None
        left = 0
        right = len(height) - 1
        
        # start compute
        while (left < right):
            
            local_ans = right - left
            
            if (height[left] < height[right]):
                
                local_ans *= height[left]
                left += 1
            elif (height[left] > height[right]):
                local_ans *= height[right]
                right -= 1
            else:
                local_ans *= height[left]
                left += 1
                right -= 1
            
            if (local_ans > CWMW_ans):
                CWMW_ans = local_ans
            
        return CWMW_ans
