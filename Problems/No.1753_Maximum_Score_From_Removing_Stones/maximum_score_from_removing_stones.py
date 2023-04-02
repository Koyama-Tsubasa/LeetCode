class Solution(object):
    def maximumScore(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """

        # parameters
        StoneAmounts = []
        moves = 0

        # start computing
        StoneAmounts = [-a, -b, -c]
        heapq.heapify(StoneAmounts)
        while StoneAmounts:
            stone1 = heapq.heappop(StoneAmounts)
            stone2 = heapq.heappop(StoneAmounts)
            if ((stone1 == 0) or (stone2 == 0)):
                break
            else:
                moves += 1
                heapq.heappush(StoneAmounts, stone1+1)
                heapq.heappush(StoneAmounts, stone2+1)

        return moves
