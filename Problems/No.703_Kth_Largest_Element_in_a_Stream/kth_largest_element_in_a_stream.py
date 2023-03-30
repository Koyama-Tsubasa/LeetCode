class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.Kth = k
        self.KminHeap = []

        for i in range(min(self.Kth, len(nums))):
            heapq.heappush(self.KminHeap, nums[i])
        for i in range(self.Kth, len(nums)):
            if (nums[i] > self.KminHeap[0]):
                heapq.heappop(self.KminHeap)
                heapq.heappush(self.KminHeap, nums[i])
        

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        if (len(self.KminHeap) < self.Kth):
            heapq.heappush(self.KminHeap, val)
        elif (val > self.KminHeap[0]):
            heapq.heappop(self.KminHeap)
            heapq.heappush(self.KminHeap, val)
        
        return self.KminHeap[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
