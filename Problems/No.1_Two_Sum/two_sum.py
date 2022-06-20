class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        # if first two sums are the solution
        if (nums[0]+nums[1] == target):
            return [0, 1]
        else:
            find = dict({nums[0]: 0, nums[1]: 1})   # dictionary which save the elements before index i
            loop_size = len(nums)                   # set the loop size
            
            # iterate the whole list once
            for i in range(2, loop_size):
                find_num = target-nums[i]   
                
                # if find out the solution then return it, else add element of index i into find
                if find_num in find:    
                    return [find[find_num], i]
                else:                 
                    find[nums[i]] = i
