class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        result = ""     # save the result
        strs.sort()     # sort strs in alphabet order
        
        # start compute
        for i in range(len(strs[0])):
            
            # check whether the alphabet is all same in index i
            if (strs[0][i] == strs[-1][i]):
                result = result + strs[0][i]
            else:
                break
        
        return result
        
