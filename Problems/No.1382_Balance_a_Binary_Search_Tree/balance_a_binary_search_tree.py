# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        # get inorder traversal of the BST
        def InOrderTraverse(node):
            if node:
                InOrderTraverse(node.left)
                InOrder.append(node.val)
                InOrderTraverse(node.right)
        
        # construct a new Balanced Binary Search Tree
        def ConstructBBST(left, right):
            if (left > right):
                return None
            else:
                mid = left + (right-left)//2
                newNode = TreeNode(InOrder[mid])
                newNode.left = ConstructBBST(left, mid-1)
                newNode.right = ConstructBBST(mid+1, right)
                return newNode
        

        # parameters
        InOrder = []
        BBST = None

        # start computing
        InOrderTraverse(root)
        BBST = ConstructBBST(0, len(InOrder)-1)

        return BBST
