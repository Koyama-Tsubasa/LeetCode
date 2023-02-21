class MyStack(object):

    def __init__(self):
        self.Stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.Stack.append(x)

    def pop(self):
        """
        :rtype: int
        """
        item = self.Stack.pop()
        return item

    def top(self):
        """
        :rtype: int
        """
        return self.Stack[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return True if not self.Stack else False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
