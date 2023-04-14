class Solution(object):
    def countTriplets(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """

        # parameters
        triplet_count = 0
        xor_idx = {}

        # start computing
        xor_sum = 0
        xor_idx[0] = [-1]
        for i, num in enumerate(arr):
            xor_sum ^= num
            if xor_sum not in xor_idx:
                xor_idx[xor_sum] = [i]
            else:
                for idx in xor_idx[xor_sum]:
                    triplet_count += i-idx-1
                xor_idx[xor_sum].append(i)
        
        return triplet_count
