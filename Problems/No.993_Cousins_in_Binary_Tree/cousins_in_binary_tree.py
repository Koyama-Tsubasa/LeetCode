# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """

        # parameters
        xParent, yParent, xDepth, yDepth = 0, 0, 0, 0
        TNodes = []

        # start computing
        TNodes.append([root, 0])
        while TNodes:
            
            [currNode, currDepth] = TNodes.pop()
            currDepth += 1

            if currNode.left:
                TNodes.append([currNode.left, currDepth])

                if (currNode.left.val == x):
                    xParent = currNode.val
                    xDepth = currDepth
                if (currNode.left.val == y):
                    yParent = currNode.val
                    yDepth = currDepth
            
            if currNode.right:
                TNodes.append([currNode.right, currDepth])

                if (currNode.right.val == x):
                    xParent = currNode.val
                    xDepth = currDepth
                if (currNode.right.val == y):
                    yParent = currNode.val
                    yDepth = currDepth
        
        return ((xDepth == yDepth) and (xParent != yParent))
