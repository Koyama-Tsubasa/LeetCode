# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        # calculate the height and if it is balanced
        def balanced_height(node):
            if (node == None):
                return [0, True]
            else:
                left = balanced_height(node.left)
                right = balanced_height(node.right)
                return [max(left[0], right[0])+1, left[1] and right[1] and (abs(left[0]-right[0])<=1)]
        
        # start compute
        if (root == None):
            return True
        else:
            left_height = balanced_height(root.left)
            right_height = balanced_height(root.right)
            return left_height[1] and right_height[1] and (abs(left_height[0]-right_height[0])<=1)
        
