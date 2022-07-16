# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        def checkSymmetric(p, q):
            
            if (p!=None and q!=None):
                return checkSymmetric(p.left, q.right) and (p.val==q.val) and checkSymmetric(p.right, q.left)
            elif (p==None and q==None):
                return True
            else:
                return False
        
        return checkSymmetric(root.left, root.right)
        
