class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        # parameters
        flag = None
        s_length, p_length = len(s), len(p)
        matching = [[None]*(s_length+1) for _ in range(p_length+1)]

        # start computing (use Dynamic Programming)
        # reference: https://reurl.cc/XL5ZV0

        # base
        matching[0][0] = True

        # check for the case of p_length = 0
        for sID in range(1, s_length+1):
            matching[0][sID] = False
        
        # check for the case of s_length = 0
        flag = True
        for pID in range(1, p_length+1):
            flag &= (p[pID-1] == '*')
            matching[pID][0] = flag

        # start matching
        for pID in range(1, p_length+1):
            for sID in range(1, s_length+1):
                if ((p[pID-1] == s[sID-1]) or (p[pID-1] == '?')):
                    matching[pID][sID] = matching[pID-1][sID-1]
                elif (p[pID-1] == '*'):
                    matching[pID][sID] = matching[pID-1][sID] or matching[pID][sID-1]
                else:
                    matching[pID][sID] = False

        return matching[p_length][s_length]
