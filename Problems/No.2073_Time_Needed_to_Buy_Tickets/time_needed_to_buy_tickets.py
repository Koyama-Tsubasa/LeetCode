class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """

        # parameters
        time_for_k = tickets[k]
        time = 0

        # start computing
        for i, t in enumerate(tickets):
            time += min(t, time_for_k)
            if (i == k):
                time_for_k -= 1
        
        return time
