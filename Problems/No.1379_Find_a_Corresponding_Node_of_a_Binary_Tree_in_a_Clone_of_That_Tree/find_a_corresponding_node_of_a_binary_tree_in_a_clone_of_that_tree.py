# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getTargetCopy(self, original, cloned, target):
        """
        :type original: TreeNode
        :type cloned: TreeNode
        :type target: TreeNode
        :rtype: TreeNode
        """

        # parameters
        Q, Q_clone = [original], [cloned]
        curr, curr_clone = None, None

        # start computing
        while Q:

            curr, curr_clone = Q.pop(), Q_clone.pop()
            if curr is target:
                return curr_clone
            
            if curr.left:
                Q.append(curr.left)
            if curr.right:
                Q.append(curr.right)
            
            if curr_clone.left:
                Q_clone.append(curr_clone.left)
            if curr_clone.right:
                Q_clone.append(curr_clone.right)
        
        return None
