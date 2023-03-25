# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        # parameters
        TNodes = []
        LL_sum = 0

        # start computing
        TNodes.append([root, False])
        while TNodes:
            [currNode, LoR] = TNodes.pop(0)
            if ((currNode.left == None) and (currNode.right == None)):
                LL_sum += currNode.val if LoR else 0
            
            if currNode.left:
                TNodes.append([currNode.left, True])
            if currNode.right:
                TNodes.append([currNode.right, False])
        
        return LL_sum
