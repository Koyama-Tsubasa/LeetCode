class RangeSum:
    def __init__(self, range_start, range_end):
        self.range_start = range_start
        self.range_end = range_end
        self.rsum = 0
        self.left = None
        self.right = None

class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.root = self.create_STree(nums, 0, len(nums)-1)

    
    def create_STree(self, vec, start, end):
        node = RangeSum(start, end)
        if (start == end):
            node.rsum = vec[start]
        else:
            mid = (start + end)//2
            node.left = self.create_STree(vec, start, mid)
            node.right = self.create_STree(vec, mid+1, end)
            node.rsum = node.left.rsum + node.right.rsum
        return node


    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self.root = self.update_path(self.root, index, val)
    

    def update_path(self, node, idx, val):
        if (idx == node.range_start == node.range_end):
            node.rsum = val
        else:
            if (node.left.range_end >= idx):
                node.left = self.update_path(node.left, idx, val)
            else:
                node.right = self.update_path(node.right, idx, val)
            node.rsum = node.left.rsum + node.right.rsum
        return node
        

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return self.CalRangeSum(self.root, left, right)
    

    def CalRangeSum(self, node, left, right):
        if ((left == node.range_start) and (right == node.range_end)):
            return node.rsum
        elif (right <= node.left.range_end):
            return self.CalRangeSum(node.left, left, right)
        elif (node.right.range_start <= left):
            return self.CalRangeSum(node.right, left, right)
        else:
            return self.CalRangeSum(node.left, left, node.left.range_end) + \
                   self.CalRangeSum(node.right, node.right.range_start, right)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
