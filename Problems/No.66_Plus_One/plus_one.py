class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        # convert digits into integer
        digits_int = int("".join(str(i) for i in digits))
        
        # convert the integer result after plus one into list
        PO_ans = list(map(int, str(digits_int+1)))
        
        return PO_ans
