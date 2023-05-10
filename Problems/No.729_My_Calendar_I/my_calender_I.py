class Event_Node:
    def __init__(self, start_date, end_date):
        self.start_date = start_date
        self.end_date = end_date
        self.before = None
        self.after = None
        

class MyCalendar(object):

    def __init__(self):
        self.root = None
    
    def check_valid(self, node, start, end):
        if not node:
            return True
        elif (start >= node.end_date):
            if not node.after:
                return True
            else:
                return self.check_valid(node.after, start, end)
        elif (end <= node.start_date):
            if not node.before:
                return True
            else:
                return self.check_valid(node.before, start, end)
    
    def update_calender(self, node, start, end):
        if not node:
            node = Event_Node(start, end)
        elif (start >= node.end_date):
            node.after = self.update_calender(node.after, start, end)
        else:
            node.before = self.update_calender(node.before, start, end)
        return node

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """

        valid = self.check_valid(self.root, start, end)
        if valid:
            self.root = self.update_calender(self.root, start, end)
        return valid
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
