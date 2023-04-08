class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        # reference:
        # https://leetcode.com/problems/minimum-height-trees/solutions/1630778/c-simple-solution-topological-sort-w-explanation/

        # parameters
        graph = [[] for _ in range(n)]
        InDegrees = [0] * n
        Roots_of_MHT = []

        # start computing
        # remove easy cases
        if (n == 1):
            return [0]
        elif (n == 2):
            return [0, 1]
        else:

            # construct graph information & indegrees
            for [node1, node2] in edges:
                graph[node1].append(node2)
                graph[node2].append(node1)
                InDegrees[node1] += 1
                InDegrees[node2] += 1
            
            # find the leaf nodes
            Leaves = []
            for nID, indegree in enumerate(InDegrees):
                if (indegree == 1):
                    Leaves.append(nID)
            
            # using BFS to remove leaf nodes iteratively
            while Leaves:
                Roots_of_MHT = []
                leaf_size = len(Leaves)
                for i in range(leaf_size):
                    leaf = Leaves.pop(0)
                    Roots_of_MHT.append(leaf)
                    for adj_node in graph[leaf]:
                        InDegrees[adj_node] -= 1
                        if (InDegrees[adj_node] == 1):
                            Leaves.append(adj_node)
            
            return Roots_of_MHT
