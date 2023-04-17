class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """

        # parameters
        target_threshold = k*threshold
        k_sum, cleared_subarrays = 0, 0

        # start computing
        for i in range(len(arr)):
            k_sum += arr[i]
            if (i < k-1):
                continue
            else:
                if (k_sum >= target_threshold):
                    cleared_subarrays += 1
                k_sum -= arr[i-k+1]
        
        return cleared_subarrays
