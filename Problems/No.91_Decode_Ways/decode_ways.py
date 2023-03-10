class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """

        # parameters
        s_length = len(s)
        DP = [0] * (s_length+1)

        # start computing
        DP[0] = 1
        DP[1] = 0 if (s[0] == '0') else 1
        for i in range(2, s_length+1):
            if (s[i-1] != '0'):
                DP[i] += DP[i-1]
            if ((s[i-2] == '1') or ((s[i-2] == '2') and (s[i-1] <= '6'))):
                DP[i] += DP[i-2]
        
        return DP[s_length]
