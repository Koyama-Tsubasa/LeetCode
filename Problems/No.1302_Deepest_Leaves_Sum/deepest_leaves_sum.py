# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        # parameters
        nodes = [root]
        curr, DL_sum, Q_size = None, None, None

        # start computing
        while nodes:
            DL_sum, Q_size = 0, len(nodes)
            for i in range(Q_size):
                curr = nodes.pop(0)
                DL_sum += curr.val
                nodes += [child for child in [curr.left, curr.right] if child]
        
        return DL_sum
