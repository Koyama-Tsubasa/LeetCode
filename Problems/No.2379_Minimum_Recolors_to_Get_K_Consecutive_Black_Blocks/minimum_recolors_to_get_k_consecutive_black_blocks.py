class Solution(object):
    def minimumRecolors(self, blocks, k):
        """
        :type blocks: str
        :type k: int
        :rtype: int
        """

        # parameters
        min_changes, num_of_w = None, 0

        # start computing
        num_of_w = blocks[:k].count('W')
        min_changes = num_of_w
        for i in range(1, len(blocks)-k+1):
            if (blocks[i-1] == 'W'):
                num_of_w -= 1
            if (blocks[i+k-1] == 'W'):
                num_of_w += 1
            min_changes = min(min_changes, num_of_w)
        
        return min_changes
