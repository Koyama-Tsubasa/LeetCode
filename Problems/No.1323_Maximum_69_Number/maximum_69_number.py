class Solution(object):
    def maximum69Number (self, num):
        """
        :type num: int
        :rtype: int
        """

        # start computing
        num = str(num)
        return int(num[:num.index('6')]+'9'+num[num.index('6')+1:] if '6' in num else num)
