class Solution {
public:
    int countTime(string time) {
        
        // parameter
        int valid_cnt = 1;

        // start computing
        if (time[0] == '?') {

            if (time[1] == '?') valid_cnt *= 24;
            else if (('0' <= time[1]) && (time[1] <= '3')) valid_cnt *= 3;
            else valid_cnt *= 2;

        }
        else if (time[1] == '?') {

            if (time[0] == '2') valid_cnt *= 4;
            else valid_cnt *= 10;

        }

        if (time[3] == '?') valid_cnt *= 6;
        if (time[4] == '?') valid_cnt *= 10;

        return valid_cnt;

    }
};
