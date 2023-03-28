class Solution(object):
    def maxSubsequence(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        # parameters
        MS_Sequence = []
        MAX_Heap = deepcopy(nums)
        LargestSum = {}
        
        # start computing
        # create MAX-Heap
        for i in range(len(MAX_Heap)):
            MAX_Heap[i] *= -1
        heapq.heapify(MAX_Heap)

        # find largest sum
        k_largest = heapq.nsmallest(k, MAX_Heap)
        for num in k_largest:
            num *= -1
            LargestSum[num] = LargestSum.get(num, 0) + 1

        # push in original order
        for num in nums:
            if (LargestSum.get(num, 0) > 0):
                MS_Sequence.append(num)
                LargestSum[num] -= 1

        return MS_Sequence
