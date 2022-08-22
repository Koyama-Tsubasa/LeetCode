# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        # parameters
        ans = []
        temp = root
        
        # start compute, using Morris Traversal
        while temp:
            if (temp.left == None):
                ans.append(temp.val)
                temp = temp.right
            else:
                prev = temp.left
                while (prev.right and prev.right!=temp):
                    prev = prev.right
                if (prev.right == None):
                    ans.append(temp.val)
                    prev.right = temp
                    temp = temp.left
                else:
                    prev.right = None
                    temp = temp.right
        
        return ans
