class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
       
        find = {}   # dictionary which save the elements before index i
        # iterate the whole list once
        for i in range(len(nums)):
            find_num = target-nums[i]   

            # if find out the solution then return it, else add element of index i into find
            if find_num in find:    
                return [find[find_num], i]
            else:                 
                find[nums[i]] = i
