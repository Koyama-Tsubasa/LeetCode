class Solution(object):
    def titleToNumber(self, columnTitle):
        """
        :type columnTitle: str
        :rtype: int
        """

        ans = 0
        for c in columnTitle:
            ans = ans*26 + (ord(c)-64)

        return ans
