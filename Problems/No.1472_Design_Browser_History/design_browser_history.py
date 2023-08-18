class BrowserHistory(object):

    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.DBH = [homepage]
        self.curPid = 0
        self.lastPid = 0
        

    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        self.curPid += 1
        if (len(self.DBH) > self.curPid):
            self.DBH[self.curPid] = url
        else:
            self.DBH.append(url)
        self.lastPid = self.curPid
        

    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.curPid = max(0, self.curPid-steps)
        return self.DBH[self.curPid]


    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.curPid = min(self.lastPid, self.curPid+steps)
        return self.DBH[self.curPid]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
