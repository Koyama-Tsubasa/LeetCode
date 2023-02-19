class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """

        # preprocessing
        intervals.append(newInterval)
        intervals.sort()

        # parameters
        j = 0
        new_intervals = []

        # start computing
        new_intervals.append(intervals[0])
        for i in range(1, len(intervals)):
            if (new_intervals[j][1] >= intervals[i][0]):
                new_intervals[j][1] = max(new_intervals[j][1], intervals[i][1])
            else:
                new_intervals.append(intervals[i])
                j += 1
        
        return new_intervals
