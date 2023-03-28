class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k1: int
        :type k2: int
        :rtype: int
        """

        # parameters
        SquaredDifference, gaps, modification = 0, 0, k1+k2
        MAX_Heap = []
        gapNum_mapping = {}

        # start computing
        # create MAX-Heap from the gap of two vectors
        for i in range(len(nums1)):
            cal_gap = (-1)*abs(nums1[i]-nums2[i])
            if (cal_gap < 0):
                gapNum_mapping[cal_gap] = gapNum_mapping.get(cal_gap, 0) + 1
                gaps += (-1)*cal_gap
        
        for gap,num in gapNum_mapping.items():
            heapq.heappush(MAX_Heap, [gap, num])
        
        # check if the gap can be eliminated
        if (gaps <= modification):
            return 0
        else:
            # modify the nums for several times
            while ((modification > 0) and MAX_Heap):
                gap1, gap2, num1, num2 = None, None, None, None
                [gap1, num1] = heapq.heappop(MAX_Heap)
                if MAX_Heap:
                    [gap2, num2] = MAX_Heap[0]
                else:
                    gap2, num2 = gap1, num1
                
                # if is is the last gap
                if (not MAX_Heap or ((gap2-gap1)*num1 > modification)):
                    modify_each = modification // num1
                    modify_advanced = modification % num1
                    heapq.heappush(MAX_Heap, [gap1+modify_each, num1-modify_advanced])
                    heapq.heappush(MAX_Heap, [gap1+modify_each+1, modify_advanced])
                    break
                else:
                    heapq.heappop(MAX_Heap)
                    heapq.heappush(MAX_Heap, [gap2, num1+num2])
                    modification -= ((gap2-gap1)*num1)
            
            # calculate the minimum square difference
            while MAX_Heap:
                [gap, num] = heapq.heappop(MAX_Heap)
                SquaredDifference += (gap**2)*num

        return SquaredDifference
