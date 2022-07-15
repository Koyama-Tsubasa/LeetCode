class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        # parameters
        left, right, mid = None, None, None
        start, end = -1, -1
        
        # start compute, using binary search method
        # find starting index
        left, right = 0, len(nums) - 1
        while (left <= right):
            
            mid = (left+right)//2
            
            if (nums[mid] == target):
                
                start = mid
                right = mid - 1
            
            elif (target < nums[mid]):
                right = mid - 1
            else:
                left = mid + 1
            
        # find ending index
        left, right = 0, len(nums) - 1
        while (left <= right):
            
            mid = (left+right)//2
            
            if (nums[mid] == target):
                
                end = mid
                left = mid + 1
            
            elif (target < nums[mid]):
                right = mid - 1
            else:
                left = mid + 1
                
        return [start, end]
        
