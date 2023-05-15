class LUPrefix(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.Vstream = set()
        self.LUP = 0
        

    def upload(self, video):
        """
        :type video: int
        :rtype: None
        """
        self.Vstream.add(video)
        while self.LUP + 1 in self.Vstream:
            self.LUP += 1
        

    def longest(self):
        """
        :rtype: int
        """
        return self.LUP
        


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
