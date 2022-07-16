# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        # parameters
        check = [[root.left, root.right]]
        
        # start compute
        while (check!=[]):
            
            left, right = check[0]
            del check[0]
            
            if (left==None and right==None):
                continue
            elif ((not left and right) or (left and not right)):
                return False
            elif (left.val != right.val):
                return False
            else:
                
                check.append([left.right, right.left])
                check.append([left.left, right.right])
                
        return True
            
        
