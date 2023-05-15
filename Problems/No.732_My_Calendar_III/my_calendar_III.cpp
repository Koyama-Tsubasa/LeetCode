class MyCalendarThree {

private:
    std::map<int, int> Calendar;
    int largest_booking = 0;

public:
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        
        Calendar[startTime]++;
        Calendar[endTime]--;
        
        int sum = 0;
        int cal_booking = 0;

        for (auto &[time, SoE]: Calendar) {

            if (time <= endTime) {
                
                sum += SoE;
                cal_booking = std::max(cal_booking, sum);

            }
            else break;

        }
        largest_booking = std::max(largest_booking, cal_booking);

        return largest_booking;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
