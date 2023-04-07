class Solution(object):
    def maxStarSum(self, vals, edges, k):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """

        # parameters
        MAX_star_sum = -float('inf')
        node_size = len(vals)
        edge_weight = [[] for _ in range(node_size)]

        # start computing
        # construct graph information
        for [a, b] in edges:
            edge_weight[a].append(vals[b])
            edge_weight[b].append(vals[a])
        
        # start compare all possible star graph
        for i in range(node_size):
            star_sum = vals[i]
            edge_information = edge_weight[i]
            edge_information.sort(reverse = True)

            for e in range(min(len(edge_information), k)):
                if (edge_information[e] > 0):
                    star_sum += edge_information[e]
                else:
                    break
            
            MAX_star_sum = max(MAX_star_sum, star_sum)

        return MAX_star_sum
