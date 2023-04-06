class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """

        # parameters
        flight_graph = [[] for _ in range(n)]
        flight = []
        price_to_dest = [float('inf')] * n

        # start computing
        # construct graph information
        for [s, d, t_cost] in flights:
            flight_graph[s].append([d, t_cost])

        # start visiting at most K stops using BFS & Dijkstra
        flight.append([src, 0])
        price_to_dest[src] = 0
        for i in range(k+1):
            flight_count = len(flight)
            for j in range(flight_count):
                [dest, cost] = flight.pop(0)
                for [next_dst, added_price] in flight_graph[dest]:
                    if ((cost + added_price) < price_to_dest[next_dst]):
                        price_to_dest[next_dst] = cost + added_price
                        flight.append([next_dst, price_to_dest[next_dst]])
        
        return price_to_dest[dst] if (price_to_dest[dst] != float('inf')) else -1
