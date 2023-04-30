class MyCircularDeque(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.MAX_size = k
        self.curr_size = 0
        self.DQueue = [0] * self.MAX_size
        self.front = 0
        

    def insertFront(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        else:
            self.front -= 1
            self.DQueue[self.front] = value
            self.curr_size += 1
            return True
        

    def insertLast(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        else:
            self.DQueue[self.front + self.curr_size] = value
            self.curr_size += 1
            return True


    def deleteFront(self):
        """
        :rtype: bool
        """
        if self.isEmpty():
            return False
        else:
            self.front += 1
            self.curr_size -= 1
            return True
        

    def deleteLast(self):
        """
        :rtype: bool
        """
        if self.isEmpty():
            return False
        else:
            self.curr_size -= 1
            return True
        

    def getFront(self):
        """
        :rtype: int
        """
        return self.DQueue[self.front] if not self.isEmpty() else -1
        

    def getRear(self):
        """
        :rtype: int
        """
        return self.DQueue[self.front + self.curr_size - 1] if not self.isEmpty() else -1
        

    def isEmpty(self):
        """
        :rtype: bool
        """
        return (self.curr_size == 0)
        

    def isFull(self):
        """
        :rtype: bool
        """
        return (self.curr_size == self.MAX_size)
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
