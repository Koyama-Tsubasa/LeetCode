class Event_Node:
    def __init__(self, start_date, end_date):
        self.start_date = start_date
        self.end_date = end_date
        self.booking_cnt = 1
        self.before = None
        self.after = None
        

class MyCalendarTwo(object):

    def __init__(self):
        self.root = None
    
    def check_valid(self, node, start, end):
        if not node:
            return True
        elif (start > node.end_date):
            return self.check_valid(node.after, start, end)
        elif (end < node.start_date):
            return self.check_valid(node.before, start, end)
        elif (node.booking_cnt < 2):
            return self.check_valid(node.before, min(start, node.start_date), max(start, node.start_date)-1) and \
                   self.check_valid(node.after, min(end, node.end_date)+1, max(end, node.end_date))
        else:
            return False
    
    def update_calendar(self, node, start, end):
        if not node:
            node = Event_Node(start, end)
        elif (start > node.end_date):
            node.after = self.update_calendar(node.after, start, end)
        elif (end < node.start_date):
            node.before = self.update_calendar(node.before, start, end)
        else:
            node.before = self.update_calendar(node.before, min(start, node.start_date), max(start, node.start_date)-1)
            node.after = self.update_calendar(node.after, min(end, node.end_date)+1, max(end, node.end_date))
            node.start_date = max(start, node.start_date)
            node.end_date = min(end, node.end_date)
            node.booking_cnt += 1
        return node

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """

        valid = self.check_valid(self.root, start, end-1)
        if valid:
            self.root = self.update_calendar(self.root, start, end-1)
        return valid


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
