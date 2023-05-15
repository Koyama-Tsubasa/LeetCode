class MyCalendarThree(object):

    def __init__(self):
        self.calendar = {}
        self.largest_booking = 0

    def book(self, startTime, endTime):
        """
        :type startTime: int
        :type endTime: int
        :rtype: int
        """
        self.calendar[startTime] = self.calendar.get(startTime, 0) + 1
        self.calendar[endTime] = self.calendar.get(endTime, 0) - 1

        partial_sum, cal_booking = 0, 0
        for [time, SoE] in sorted(self.calendar.items()):
            if (time <= endTime):
                partial_sum += SoE
                cal_booking = max(cal_booking, partial_sum)
            else:
                break
        self.largest_booking = max(self.largest_booking, cal_booking)

        return self.largest_booking
        


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
