class Solution(object):
    def findCenter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        
        return edges[0][0] if ((edges[0][0] == edges[1][0]) or (edges[0][0] == edges[1][1])) else edges[0][1]
