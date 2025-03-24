class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int days_without_meeting = 0;

        int last_meeting_end = 0;
        sort(meetings.begin(), meetings.end());
        for (auto meeting: meetings) {

            int start = meeting[0], end = meeting[1];
            if (start > last_meeting_end + 1) days_without_meeting += (start-last_meeting_end-1);
            last_meeting_end = max(end, last_meeting_end);

        }

        days_without_meeting += (days-last_meeting_end);
        return days_without_meeting;

    }
};
