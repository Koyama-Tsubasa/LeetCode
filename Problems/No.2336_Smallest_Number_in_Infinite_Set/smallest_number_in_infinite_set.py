class SmallestInfiniteSet(object):

    def __init__(self):
        self.isInSet = {}
        self.InfiniteSet = []
        for i in range(1, 1001):
            self.isInSet[i] = True
            heapq.heappush(self.InfiniteSet, i)

    def popSmallest(self):
        """
        :rtype: int
        """

        smallest = heapq.heappop(self.InfiniteSet)
        self.isInSet[smallest] = False

        return smallest
        

    def addBack(self, num):
        """
        :type num: int
        :rtype: None
        """

        if not self.isInSet[num]:
            heapq.heappush(self.InfiniteSet, num)
            self.isInSet[num] = True

        
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
