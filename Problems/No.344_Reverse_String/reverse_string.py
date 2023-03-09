class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """

        # parameters
        left, right = 0, len(s)-1

        # start computing
        while (left < right):
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
