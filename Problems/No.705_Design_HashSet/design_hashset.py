class MyHashSet(object):

    def __init__(self):
        self.HashSet = {}


    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.HashSet[key] = True
        

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.HashSet[key] = False
        

    def contains(self, key):
        """
        :type key: int
        :rtype: bool
        """
        if key in self.HashSet:
            return self.HashSet[key]
        else:
            return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
