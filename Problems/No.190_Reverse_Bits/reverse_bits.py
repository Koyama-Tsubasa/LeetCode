class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):

        # convert int into bitset
        bit = format(n, "032b")

        # reverse the bitset followed by converting into int
        return int(bit[::-1], 2)
