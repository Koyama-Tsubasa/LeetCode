class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        # parameters
        left, right, mid = 0, len(nums) - 1, None
        
        # start compute, use modified binary search
        while (left <= right):
            
            mid = (left+right)//2
            
            if (nums[mid] == target):
                return mid
            else:
                
                # check which part is normally sorted
                if (nums[left] <= nums[mid]):
                    
                    if (nums[left]<=target and target<=nums[mid]):
                        right = mid - 1
                    else:
                        left = mid + 1
                
                else:
                    
                    if (nums[mid]<=target and target<=nums[right]):
                        left = mid + 1
                    else:
                        right = mid - 1
        
        return -1
        
