class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """

        # parameter
        friends = range(1, n+1)

        # start computing
        while (len(friends) > 1):
            for i in range(1, k):
                friends.append(friends.pop(0))
            friends.pop(0)

        return friends[0]
