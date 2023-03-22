# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumEvenGrandparent(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        # parameters
        EG_sum = 0
        CNode = None
        Nodes = []

        # start computing
        if not root:
            return 0
        else:
            Nodes.append(root)
            while Nodes:
                CNode = Nodes.pop(0)
                if (CNode.val%2 == 0):
                    if CNode.left:
                        EG_sum += CNode.left.left.val if CNode.left.left else 0
                        EG_sum += CNode.left.right.val if CNode.left.right else 0
                    if CNode.right:
                        EG_sum += CNode.right.right.val if CNode.right.right else 0
                        EG_sum += CNode.right.left.val if CNode.right.left else 0
                if CNode.left:
                    Nodes.append(CNode.left)
                if CNode.right:
                    Nodes.append(CNode.right)
            return EG_sum    
