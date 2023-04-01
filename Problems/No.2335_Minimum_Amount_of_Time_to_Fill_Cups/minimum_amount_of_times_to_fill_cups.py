class Solution(object):
    def fillCups(self, amount):
        """
        :type amount: List[int]
        :rtype: int
        """

        # parameters
        CupAmount = []
        times = 0

        # start computing
        for cup in amount:
            if (cup > 0):
                heapq.heappush(CupAmount, (-1)*cup)
        
        while CupAmount:
            cup_largest = heapq.heappop(CupAmount) + 1

            if CupAmount:
                cup_second = heapq.heappop(CupAmount) + 1
                if (cup_second < 0):
                    heapq.heappush(CupAmount, cup_second)

            if (cup_largest < 0):
                heapq.heappush(CupAmount, cup_largest)
            times += 1

        return times
