class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.numArray = []
        for num in nums:
            self.numArray.append(num)

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        
        # parameter
        Sum = 0

        # start computing
        for i in range(left, right+1):
            Sum += self.numArray[i]
        
        return Sum


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
