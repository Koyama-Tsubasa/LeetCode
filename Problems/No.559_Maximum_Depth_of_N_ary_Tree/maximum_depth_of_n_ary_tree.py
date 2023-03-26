"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """

        # parameters
        TNodes = []
        MaxDepth = 0

        # start computing
        if (root == None):
            return 0
        TNodes.append(root)
        while TNodes:
            LevelSize = len(TNodes)
            for i in range(LevelSize):
                currNode = TNodes.pop(0)
                for child in currNode.children:
                    TNodes.append(child)
            MaxDepth += 1

        return MaxDepth        
