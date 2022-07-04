class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        
        # the mapping of integer to roman
        int_to_roman = [
            [1000, "M"],
            [900, "CM"],
            [500, "D"],
            [400, "CD"],
            [100, "C"],
            [90, "XC"],
            [50, "L"],
            [40, "XL"],
            [10, "X"],
            [9, "IX"],
            [5, "V"],
            [4, "IV"],
            [1, "I"]
        ]
        ItR_ans = ""
        
        # start compute
        for integer, roman in int_to_roman:
            while (num >= integer):
                num -= integer
                ItR_ans += roman
                
        return ItR_ans
