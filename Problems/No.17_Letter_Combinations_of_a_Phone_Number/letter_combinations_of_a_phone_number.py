class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        # mapping from digit to letters
        DL_mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        LCoaPN_ans = []
        temp = 0
        
        # start compute
        for n in digits:
            
            # check if it is the first digit
            if LCoaPN_ans: 
                temp = len(LCoaPN_ans)
                for e in range(temp):
                    element = LCoaPN_ans[0]
                    for alphabet in DL_mapping[n]:
                        LCoaPN_ans.append(element+alphabet)
                    del LCoaPN_ans[0]
            else:
                for alphabet in DL_mapping[n]:
                    LCoaPN_ans.append(alphabet)
        
        return LCoaPN_ans
        
