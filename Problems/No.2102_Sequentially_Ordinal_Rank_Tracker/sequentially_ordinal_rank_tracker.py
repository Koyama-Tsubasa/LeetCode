# reference:
# https://leetcode.com/problems/sequentially-ordinal-rank-tracker/solutions/1626463/python-bisect-o-n/?q=python&orderBy=most_relevant
class SORTracker(object):

    def __init__(self):
        self.locations = []
        self.count = 0

    def add(self, name, score):
        """
        :type name: str
        :type score: int
        :rtype: None
        """
        bisect.insort(self.locations, (-(score), name))

    def get(self):
        """
        :rtype: str
        """
        output = self.locations[self.count]
        self.count += 1
        return output[1]
        


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
