class Solution(object):
    def countDays(self, days, meetings):
        """
        :type days: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        
        days_without_meeting = 0
        
        last_meeting_end = 0
        meetings.sort()
        for start, end in meetings:
            if (start > last_meeting_end + 1):
                days_without_meeting += (start-last_meeting_end-1)
            last_meeting_end = max(end, last_meeting_end)
        
        days_without_meeting += (days-last_meeting_end)
        return days_without_meeting
