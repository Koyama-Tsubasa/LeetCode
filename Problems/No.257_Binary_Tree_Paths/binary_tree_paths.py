# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """

        # function: searchBTpaths
        # search all Binary Tree paths
        def searchBTpaths(tNode, temp):
            if not tNode:
                return
            else:
                temp += str(tNode.val)
                if ((not tNode.left) and (not tNode.right)):
                    BTPaths.append(temp)
                else:
                    temp += "->"
                    searchBTpaths(tNode.left, temp)
                    searchBTpaths(tNode.right, temp)

        # parameter
        BTPaths = []

        # start computing
        searchBTpaths(root, "")

        return BTPaths
