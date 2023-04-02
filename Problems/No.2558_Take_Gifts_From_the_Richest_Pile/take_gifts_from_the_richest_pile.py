class Solution(object):
    def pickGifts(self, gifts, k):
        """
        :type gifts: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        GiftPiles = []
        remaining_gifts = 0

        # start computing
        for initial_gift in gifts:
            heapq.heappush(GiftPiles, (-1)*initial_gift)
        for i in range(k):
            gift = int(((-1)*heapq.heappop(GiftPiles))**0.5)
            heapq.heappush(GiftPiles, (-1)*gift)
        while GiftPiles:
            remaining_gifts += (-1)*heapq.heappop(GiftPiles)

        return remaining_gifts
