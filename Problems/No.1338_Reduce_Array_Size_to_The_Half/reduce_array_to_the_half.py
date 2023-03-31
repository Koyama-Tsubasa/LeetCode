class Solution(object):
    def minSetSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """

        # parameters
        removed_set_num = 0
        IntSize = {}
        IntSetSize = []

        # start computing
        # calculate the size of each integer & order them
        for n in arr:
            IntSize[n] = IntSize.get(n, 0) + 1
        for [Int, Size] in IntSize.items():
            heapq.heappush(IntSetSize, [(-1)*Size, Int])

        # removing them iteratively
        removed_size = 0
        while ((-1)*removed_size < len(arr)//2):
            removed_set_num += 1
            removed_size += heapq.heappop(IntSetSize)[0]

        return removed_set_num
