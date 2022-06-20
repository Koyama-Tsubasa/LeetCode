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
            find = [nums[0], nums[1]]   # list which save the elements before index i
            loop_size = len(nums)       # set the loop size
            for i in range(2, loop_size):
                find_num = target-nums[i]   
                if find_num in find:    # find out the solution then return it
                    return [find.index(find_num), i]
                else:                   # add element of index i into find
                    find.append(nums[i])
