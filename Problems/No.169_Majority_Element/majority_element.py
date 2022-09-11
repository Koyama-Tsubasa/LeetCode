class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # parameters
        counter = 0
        majority = 0
        
        # start compute, using moores voting algorithm
        for n in nums:
            if counter == 0:
                majority = n
            if majority == n:
                counter += 1
            else:
                counter -= 1
        
        return majority
