class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """

        # parameters
        MAX_length = 0
        n1_size, n2_size = len(nums1), len(nums2)
        DP = [[0] * (n2_size+1) for _ in range(n1_size+2)]
        
        # start computing
        for i in range(1, n1_size+1):
            for j in range(1, n2_size+1):
                if (nums1[i-1] == nums2[j-1]):
                    DP[i][j] = DP[i-1][j-1] + 1
                else:
                    DP[i][j] = 0
                MAX_length = max(MAX_length, DP[i][j])
        
        return MAX_length
