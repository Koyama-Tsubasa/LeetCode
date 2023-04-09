class Solution(object):
    def countRestrictedPaths(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """

        # reference:
        # https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/solutions/3332377/c-well-commented-avoid-getting-wa-in-the-last-testcase/

        # Function: find restricted paths from source (s) to destination (d)
        def FindRestrictedPaths(s, d):
            if (s == d):
                return 1
            elif (restricted_paths[s] != -1):
                return restricted_paths[s]
            else:
                Rpath = 0
                for [adjNode, EWeight] in graph[s]:
                    if (dist[adjNode] < dist[s]):
                        Rpath = (Rpath + FindRestrictedPaths(adjNode, d)) % 1000000007
                restricted_paths[s] = Rpath
                return Rpath

        # parameters
        restricted_paths_to_n = 0
        graph = [[] for _ in range(n+1)]
        dist = [float('inf')] * (n+1)
        restricted_paths = [-1] * (n+1)

        # create graph information
        for [node1, node2, weight] in edges:
            graph[node1].append([node2, weight])
            graph[node2].append([node1, weight])
        
        # find the shortest path from node n using Dijkstra's Algorithm
        min_path = []
        heapq.heappush(min_path, [0, n])
        dist[n] = 0
        while min_path:
            [curr_weight, curr_node] = heapq.heappop(min_path)
            for [adj_node, edge_weight] in graph[curr_node]:
                if (dist[adj_node] > dist[curr_node] + edge_weight):
                    dist[adj_node] = dist[curr_node] + edge_weight
                    heapq.heappush(min_path, [dist[adj_node], adj_node])
        
        # find all possible restricted paths to n
        restricted_paths_to_n = FindRestrictedPaths(1, n)

        return restricted_paths_to_n
