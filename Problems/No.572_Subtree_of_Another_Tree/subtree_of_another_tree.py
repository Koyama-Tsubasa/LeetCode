# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def PreOrder(self, r_node, sr_val, psr_nodes):
        if not r_node:
            return
        if (r_node.val == sr_val):
            psr_nodes.append(r_node)
        self.PreOrder(r_node.left, sr_val, psr_nodes)
        self.PreOrder(r_node.right, sr_val, psr_nodes)
    
    def is_same(self, node1, node2):
        if not node1 and not node2:
            return True
        elif not node1 or not node2:
            return False
        elif (node1.val != node2.val):
            return False
        else:
            return self.is_same(node1.left, node2. left) and self.is_same(node1.right, node2.right)

    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """

        # parameter
        potential_subroots = []

        # start computing
        self.PreOrder(root, subRoot.val, potential_subroots)
        for node in potential_subroots:
            if self.is_same(node, subRoot):
                return True
        
        return False
