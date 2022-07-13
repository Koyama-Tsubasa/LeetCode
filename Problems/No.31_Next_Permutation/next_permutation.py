class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        # parameters
        swap_h, swap_nh = len(nums)-2, 0
        
        # find the number which can be swapped 
        while (nums[swap_h]>=nums[swap_h+1] and swap_h>=0):
            swap_h -= 1
        
        # check if the given is in decreasing order
        if (swap_h == -1):
            nums.reverse()
        else:
            
            # find the number which to swapped, becomes the new sub_header
            for swap_nh in range(len(nums)-1, swap_h, -1):
                if (nums[swap_nh] > nums[swap_h]):
                    break
             
            # swap the found two numbers and sort the numbers after sub_header
            nums[swap_h], nums[swap_nh] = nums[swap_nh], nums[swap_h]
            nums[swap_h+1:] = sorted(nums[swap_h+1:])
        
        
