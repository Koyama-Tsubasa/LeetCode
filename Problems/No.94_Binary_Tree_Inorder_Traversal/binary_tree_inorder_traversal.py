# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        # Binary Tree Inorder Traversal
        def BTIT(node):
            if node:
                BTIT(node.left)
                BTIT_ans.append(node.val)
                BTIT(node.right)
                
        # parameter
        BTIT_ans = []
        
        # start compute
        if root:
            BTIT(root.left)
            BTIT_ans.append(root.val)
            BTIT(root.right)
        
        return BTIT_ans
