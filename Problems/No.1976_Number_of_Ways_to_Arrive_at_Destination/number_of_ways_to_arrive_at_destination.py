class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """

        # global parameters
        MOD = int(1e9 + 7)
        edges = [[] for _ in range(n)]
        
        # start computing
        # construct graph (edge relationships)
        for [node1, node2, dis] in roads:
            edges[node1].append([node2, dis])
            edges[node2].append([node1, dis])

        # traverse using Dijkstra's Algorithm
        # local parameters
        traverse_count = 0
        min_path = []
        dist, paths = [float('inf')] * n, [0] * n

        # start traverse
        dist[0] = 0
        paths[0] = 1
        heapq.heappush(min_path, [0, 0])

        while (traverse_count < n):
            [curr_dist, curr_node] = heapq.heappop(min_path)
            if (dist[curr_node] < curr_dist):
                continue
            else:
                traverse_count += 1
                # update the distance to the adjacent node from current node
                for [adj_node, edgeW] in edges[curr_node]:
                    updated_dist = curr_dist + edgeW
                    
                    if (updated_dist < dist[adj_node]):
                        dist[adj_node] = updated_dist
                        heapq.heappush(min_path, [updated_dist, adj_node])
                        paths[adj_node] = paths[curr_node]
                    elif (updated_dist == dist[adj_node]):
                        paths[adj_node] = (paths[adj_node] + paths[curr_node]) % MOD

        return (paths[-1] % MOD)
