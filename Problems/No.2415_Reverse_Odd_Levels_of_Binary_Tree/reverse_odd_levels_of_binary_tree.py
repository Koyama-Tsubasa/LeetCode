# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def reverseOddLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """

        # parameters
        Odd = False
        TNodes = []
        LevelValues = []

        # start computing
        TNodes.append(root)
        while TNodes:

            if not Odd:
                LevelValues = []
            
            LevelNodes = len(TNodes)
            for i in range(LevelNodes):
                currNode = TNodes.pop(0)

                if Odd:
                    currNode.val = LevelValues[LevelNodes-1-i]
                
                if currNode.left:
                    TNodes.append(currNode.left)
                    LevelValues.append(currNode.left.val)
                if currNode.right:
                    TNodes.append(currNode.right)
                    LevelValues.append(currNode.right.val)
            
            Odd ^= True
        
        return root
