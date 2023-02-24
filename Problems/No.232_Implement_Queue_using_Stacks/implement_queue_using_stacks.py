class MyQueue(object):

    def __init__(self):
        self.Input = []
        self.Output = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.Input.append(x)
        

    def pop(self):
        """
        :rtype: int
        """
        self.peek()
        num = self.Output[-1]
        self.Output.pop()
        return num
        

    def peek(self):
        """
        :rtype: int
        """
        if not self.Output:
            while self.Input:
                self.Output.append(self.Input[-1])
                self.Input.pop()
        return self.Output[-1]
        

    def empty(self):
        """
        :rtype: bool
        """
        return not (self.Input or self.Output)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
