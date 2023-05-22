class Solution(object):

    # find the answer for each equation using DFS
    def DFS(self, val, node, dest, visited, Graph):
        # check if node, dest is in Graph
        if node not in Graph or dest not in Graph:
            return -1.0
        
        # check if visit the destination
        if (node == dest):
            return val
        else:
            for [next_node, ans] in Graph[node].items():
                if next_node not in visited:
                    visited.append(next_node)
                    temp = self.DFS(val*ans, next_node, dest, visited, Graph)
                    if (temp != -1.0):
                        return temp
            return -1.0


    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """

        # parameters
        Equations = []

        # start computing
        # build Equation Graph
        Graph = {}
        for (node1, node2), value in zip(equations, values):
            Graph.setdefault(node1, {})[node2] = value
            Graph.setdefault(node2, {})[node1] = 1/value

        # start compute for each equation using DFS
        visited = []
        for [source, dest] in queries:
            visited = []
            Equations.append(self.DFS(1, source, dest, visited, Graph))

        return Equations
