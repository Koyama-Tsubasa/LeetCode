class Solution(object):
    def containsPattern(self, arr, m, k):
        """
        :type arr: List[int]
        :type m: int
        :type k: int
        :rtype: bool
        """

        # parameter
        pattern_cnt = 0

        # start computing
        if (len(arr) < m*k):
            return False
        for i in range(len(arr)-m):
            if (arr[i] == arr[i+m]):
                pattern_cnt += 1
            else:
                pattern_cnt = 0
            
            if (pattern_cnt == m*(k-1)):
                return True
        
        return False
