class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: int
        """

        # reference
        # https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/solutions/2298548/c-java-python-subarray-sum-explained/

        # parameters
        target_count = 0
        row_num, col_num = len(matrix), len(matrix[0])
        preSum = [[0] * col_num for _ in range(row_num)]

        # start computing
        # first check for the initial condition
        if not row_num:
            return 0
        
        # calculate prefix sum for each row
        for row in range(row_num):
            preSum_tempR = 0
            for col in range(col_num):
                preSum_tempR += matrix[row][col]
                preSum[row][col] = preSum_tempR
        
        # check for matches
        counter = {}
        for colS in range(col_num):
            for col in range(colS, col_num):
                counter = {0: 1}
                partial_sum = 0
                for row in range(row_num):
                    partial_sum += preSum[row][col] - (preSum[row][colS-1] if (colS > 0) else 0)
                    target_count += counter[partial_sum - target] if (partial_sum - target) in counter else 0
                    counter[partial_sum] = counter.get(partial_sum, 0) + 1

        return target_count
