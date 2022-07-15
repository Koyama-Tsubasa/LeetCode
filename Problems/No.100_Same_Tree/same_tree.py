# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        
        # start compute, using inorder traversal method
        if (p!=None and q!=None):
            return self.isSameTree(p.left, q.left) and (p.val==q.val) and self.isSameTree(p.right, q.right)
        elif (p==None and q==None):
            return True
        else:
            return False
        
