class Solution(object):
    def validPath(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """

        # parameters
        edgelist = [[] for _ in range(n)]
        arrivable_nodes = [False]*n
        node2go = []
        curr = None
        
        # start computing
        # collate edges
        for edge in edges:
            edgelist[edge[0]].append(edge[1])
            edgelist[edge[1]].append(edge[0])
        
        # start visiting
        node2go.append(source)
        arrivable_nodes[source] = True
        while node2go:
            curr = node2go.pop(0)
            if (curr == destination):
                return True
            else:
                for node in edgelist[curr]:
                    if not arrivable_nodes[node]:
                        arrivable_nodes[node] = True
                        node2go.append(node)
        
        return False
