class Solution(object):
    def countSubgraphsForEachDiameter(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        # parameters
        dis_cnt = [0] * (n-1)
        edge_info = [[] for _ in range(n)]

        # start computing
        # construct edge information
        for [city_1, city_2] in edges:
            edge_info[city_1-1].append(city_2)
            edge_info[city_2-1].append(city_1)
        
        # check all possible subsets
        dis_cnt[0] = len(edges)
        for i in range(2**n):
            # decide current subset and check if it's size >= 3
            curr_subset = []
            for j in range(n):
                if ((i & (1<<j)) != 0):
                    curr_subset.append(j+1)
            if (len(curr_subset) < 3):
                continue
            
            # calculate the max distance of this subset
            MAX_distance = 0
            for city in curr_subset:
                curr_distance = -1
                subset_copy = curr_subset[:]

                # visit from each city in the current subset using BFS
                visit_city = []
                visit_city.append(city)
                subset_copy.remove(city)
                while visit_city:
                    curr_distance += 1
                    Q_size = len(visit_city)
                    for cnt in range(Q_size):
                        curr_city = visit_city.pop(0)
                        for next_city in edge_info[curr_city-1]:
                            if next_city in subset_copy:
                                visit_city.append(next_city)
                                subset_copy.remove(next_city)
                
                # check if every cities in the subset can be visited
                if subset_copy:
                    break
                else:
                    MAX_distance = max(MAX_distance, curr_distance)
            
            if (MAX_distance > 1):
                dis_cnt[MAX_distance-1] += 1

        return dis_cnt

