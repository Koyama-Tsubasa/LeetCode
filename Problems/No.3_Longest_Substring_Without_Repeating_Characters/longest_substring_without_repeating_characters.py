class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # to store the answer and the unrepeated substring
        LSWRC_ans = 0
        unrepeated = ""
        
        # start compute
        for c in s:
            
            # check if c in unrepeated substring
            if c not in unrepeated:
                unrepeated += c
            else:
              
                # update answer and unrepeated substring
                LSWRC_ans = max(LSWRC_ans, len(unrepeated))
                unrepeated = unrepeated[unrepeated.index(c)+1:] + c
     
        return LSWRC_ans if LSWRC_ans > len(unrepeated) else len(unrepeated)
