class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

        # parameters
        merged_intervals = []

        # start computing
        intervals.sort()
        for interval in intervals:
            if (not merged_intervals or merged_intervals[-1][1] < interval[0]):
                merged_intervals.append(interval)
            else:
                merged_intervals[-1][1] = max(merged_intervals[-1][1], interval[1])
        
        return merged_intervals
