class MyCalendarTwo {

private:
    std::map<int, int> events;

public:
    bool book(int start, int end) {

        int booking_cnt = 0;
        events[start]++;
        events[end]--;

        for (auto &[event_time, SE_cnt]: events) {

            booking_cnt += SE_cnt;
            if (booking_cnt >= 3) {

                events[start]--;
                events[end]++;
                return false;

            }

        }
        
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
