class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """

        # convert int into bitset & count 1s
        bit_string = format(n, "032b")
        return bit_string.count("1")
