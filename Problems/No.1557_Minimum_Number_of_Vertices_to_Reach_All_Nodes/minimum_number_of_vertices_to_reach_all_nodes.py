class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        # parameters
        starting_nodes = []
        node_no_InDegree = [True]*n

        # start computing
        for [outN, inN] in edges:
            node_no_InDegree[inN] = False
        for i in range(n):
            if node_no_InDegree[i]:
                starting_nodes.append(i)

        return starting_nodes
