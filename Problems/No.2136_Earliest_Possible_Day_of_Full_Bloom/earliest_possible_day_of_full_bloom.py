class Solution(object):
    def earliestFullBloom(self, plantTime, growTime):
        """
        :type plantTime: List[int]
        :type growTime: List[int]
        :rtype: int
        """

        # parameters
        pT_sum, earliest_possible_day = 0, 0

        # start computing
        for gT, pT in sorted(zip(growTime, plantTime), reverse=True):
            pT_sum += pT
            earliest_possible_day = max(earliest_possible_day, pT_sum+gT)

        return earliest_possible_day
