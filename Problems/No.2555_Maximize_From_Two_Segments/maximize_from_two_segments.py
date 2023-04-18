class Solution(object):
    def maximizeWin(self, prizePositions, k):
        """
        :type prizePositions: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        partial_start = 0
        max_win_2segs = 0
        max_wins = [0] * (len(prizePositions)+1)

        # start computing
        for i in range(len(prizePositions)):
            
            # find the partial start point of the current subarray to index i
            while (prizePositions[i] > prizePositions[partial_start]+k):
                partial_start += 1
            
            # calculate the maximum wins at the current position
            max_wins[i+1] = max(max_wins[i], i-partial_start+1)

            # find the maximum wins with two segments at the current position
            max_win_2segs = max(max_win_2segs, i-partial_start+1 + max_wins[partial_start])
        
        return max_win_2segs
