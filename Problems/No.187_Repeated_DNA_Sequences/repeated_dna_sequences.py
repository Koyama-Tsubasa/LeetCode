class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        # parameter
        DNA_cnt = {}

        # start computing
        if (len(s) <= 10):
            return []
        for i in range(len(s)-10+1):
            sub_DNA = s[i:i+10]
            DNA_cnt[sub_DNA] = DNA_cnt.get(sub_DNA, 0) + 1
        
        return [sDNA for [sDNA, cnt] in DNA_cnt.items() if (cnt > 1)]
