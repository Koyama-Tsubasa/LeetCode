class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """

        # parameters
        InDegree, OutDegree = [0]*n, [0]*n

        # start computing
        if (len(trust) >= n-1):
            for [trust, is_trusted] in trust:
                InDegree[is_trusted-1] += 1
                OutDegree[trust-1] += 1
            for i in range(n):
                if ((InDegree[i] == n-1) and (OutDegree[i] == 0)):
                    return i+1
        
        return -1
