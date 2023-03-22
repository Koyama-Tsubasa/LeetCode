# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def mergeTrees(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: TreeNode
        """

        # parameters
        TNodes = []
        curr_pair = []

        # start computing
        if (root1 == None):
            return root2
        elif (root2 == None):
            return root1
        else:
            TNodes.append([root1, root2])
            while TNodes:
                curr_pair = TNodes.pop(0)
                if ((curr_pair[0] == None) or (curr_pair[1] == None)):
                    continue
                else:
                    curr_pair[0].val += curr_pair[1].val
                    if curr_pair[0].left:
                        TNodes.append([curr_pair[0].left, curr_pair[1].left])
                    else:
                        curr_pair[0].left = curr_pair[1].left
                    if curr_pair[0].right:
                        TNodes.append([curr_pair[0].right, curr_pair[1].right])
                    else:
                        curr_pair[0].right = curr_pair[1].right
            return root1
