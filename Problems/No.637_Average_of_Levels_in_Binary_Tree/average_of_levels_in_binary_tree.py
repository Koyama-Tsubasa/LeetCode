# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """

        # parameters
        AverageValues = []
        LevelValues = []

        # start computing
        LevelValues.append(root)
        while LevelValues:
            levelAverage = 0.0
            LevelSize = len(LevelValues)
            for i in range(LevelSize):
                currNode = LevelValues.pop(0)
                levelAverage += float(currNode.val)
                if currNode.left:
                    LevelValues.append(currNode.left)
                if currNode.right:
                    LevelValues.append(currNode.right)
            AverageValues.append(levelAverage/LevelSize)
        
        return AverageValues
