class RecentCounter(object):

    def __init__(self):
        self.recent_calls = []

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """

        self.recent_calls.append(t)
        while (self.recent_calls[0] < t-3000):
            self.recent_calls.pop(0)
        return len(self.recent_calls)
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
