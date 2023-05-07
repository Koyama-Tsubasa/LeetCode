class Solution(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        :type total: int
        :type cost1: int
        :type cost2: int
        :rtype: int
        """

        # parameters
        cnt = 0
        higher_cost = max(cost1, cost2)
        lower_cost = min(cost1, cost2)

        # start computing
        remains = total
        for i in range(total//higher_cost + 1):
            cnt += (remains//lower_cost + 1)
            remains -= higher_cost
        
        return cnt
