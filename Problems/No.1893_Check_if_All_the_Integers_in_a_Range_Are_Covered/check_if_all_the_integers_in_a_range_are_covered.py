class Solution(object):
    def isCovered(self, ranges, left, right):
        """
        :type ranges: List[List[int]]
        :type left: int
        :type right: int
        :rtype: bool
        """

        # parameter
        check_range = [False] * (right-left+1)

        # start computing
        for [rangeL, rangeR] in ranges:
            for i in range(max(rangeL, left), min(rangeR, right)+1):
                check_range[i-left] = True
        
        return True if False not in check_range else False
