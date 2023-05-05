class Solution(object):
    def largestTimeFromDigits(self, arr):
        """
        :type arr: List[int]
        :rtype: str
        """

        # parameter
        valid_time = []

        # start computing
        for d0, d1, d2, d3 in list(itertools.permutations(arr, 4)):
            hrs = d0*10 + d1
            if ((hrs < 24) and (d2 < 6)):
                valid_time.append([hrs, d2*10 + d3])
        
        if not valid_time:
            return ""
        else:
            hrs, mins = max(valid_time)
            return str(hrs).rjust(2, '0') + ":" + str(mins).rjust(2, '0')
