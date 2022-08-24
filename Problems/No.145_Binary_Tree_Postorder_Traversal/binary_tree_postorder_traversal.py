# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        # postorder traversal
        def PostOrder(node):
            if (node == None):
                return
            else:
                PostOrder(node.left)
                PostOrder(node.right)
                ans.append(node.val)
        
        ans = []            # parameter
        PostOrder(root)     # start compute
        return ans
