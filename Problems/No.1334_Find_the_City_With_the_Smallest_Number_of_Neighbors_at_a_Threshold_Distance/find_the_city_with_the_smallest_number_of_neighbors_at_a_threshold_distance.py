class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type distanceThreshold: int
        :rtype: int
        """

        # parameter
        c2c_dist = [[float('inf') for _ in range(n)] for _ in range(n)]

        # start computing
        # Floyd Warshall for all paths
        for [c1, c2, val] in edges:
            c2c_dist[c1][c2] = val
            c2c_dist[c2][c1] = val
        for i in range(n):
            c2c_dist[i][i] = 0
        
        for mid in range(n):
            for start in range(n):
                for end in range(n):
                    if ((c2c_dist[start][mid] == float('inf')) or (c2c_dist[mid][end] == float('inf'))):
                        continue
                    else:
                        c2c_dist[start][end] = min(c2c_dist[start][end], c2c_dist[start][mid] + c2c_dist[mid][end])
        
        # find the greatest number of smallest reachable cities
        Gcity = -1
        Mcity_num = n

        for city in range(n):
            cnt = 0
            for adj_city in range(n):
                if (c2c_dist[city][adj_city] <= distanceThreshold):
                    cnt += 1
            if (cnt <= Mcity_num):
                Mcity_num = cnt
                Gcity = city
        
        return Gcity
