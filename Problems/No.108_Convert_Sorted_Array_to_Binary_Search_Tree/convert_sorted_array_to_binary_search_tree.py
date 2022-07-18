# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        
        if nums:
            
            mid = len(nums)//2
            new_node = TreeNode(nums[mid])
            new_node.left = self.sortedArrayToBST(nums[:mid])
            new_node.right = self.sortedArrayToBST(nums[mid+1:])
            
            return new_node
        
