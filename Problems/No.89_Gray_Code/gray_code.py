class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        # parameters
        GCode = [0, 1]
        cNum = None

        # start computing
        for i in range(2, (1<<n)):
            cNum = i ^ (i>>1)
            GCode.append(cNum)

        return GCode
