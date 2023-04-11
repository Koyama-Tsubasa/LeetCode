class Solution(object):
    def canReach(self, s, minJump, maxJump):
        """
        :type s: str
        :type minJump: int
        :type maxJump: int
        :rtype: bool
        """

        # parameters
        s_length = len(s)
        index = []

        # start computing
        if (s[-1] == '1'):
            return False
        MAX_idx = 0
        index.append(0)
        while index:
            idx = index.pop(0)
            for i in range(max(idx+minJump, MAX_idx+1), min(s_length, idx+maxJump+1)):
                if (s[i] == '0'):
                    if (i == s_length-1):
                        return True
                    index.append(i)
            MAX_idx = idx + maxJump
        
        return False
