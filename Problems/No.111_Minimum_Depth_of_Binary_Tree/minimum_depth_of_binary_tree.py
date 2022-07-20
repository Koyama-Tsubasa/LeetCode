# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        # parameters
        Q = []
        depth = 0
        
        # start compute, using BFS method
        if not root:
            return 0
        else:
            Q.append(root)
            while (len(Q)):
                Q_length = len(Q)
                for i in range(Q_length):
                    temp = Q[0]
                    del Q[0]
                    
                    if (temp.left==None and temp.right==None):
                        return depth + 1
                    else:
                        if (temp.left):
                            Q.append(temp.left)
                        if (temp.right):
                            Q.append(temp.right)
                depth += 1
            return depth
            
