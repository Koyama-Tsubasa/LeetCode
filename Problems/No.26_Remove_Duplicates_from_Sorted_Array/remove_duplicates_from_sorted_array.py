class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        index = 1       # the current index
        RDA_size = 1    # the size of remove duplicates array
        
        # start compute
        while (index<len(nums)):
            
            # check if the numner is different from the previous one
            if (nums[index-1] != nums[index]):
                nums[RDA_size] = nums[index];
                RDA_size += 1
            index += 1
        
        return RDA_size
