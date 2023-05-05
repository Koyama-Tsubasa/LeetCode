class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        // parameter
        std::string latest_time = "";
        std::vector<int> temp_time;

        // start computing
        std::sort(arr.begin(), arr.end());
        do {

            int hr = arr[0]*10 + arr[1];
            if ((hr < 24) && (arr[2] < 6)) temp_time = arr;
            else if (hr >= 24) break;
            else continue;

        } while (std::next_permutation(arr.begin(), arr.end()));

        if (temp_time.empty()) return "";
        else {

            latest_time = std::to_string(temp_time[0]) + std::to_string(temp_time[1]) + ":"
                        + std::to_string(temp_time[2]) + std::to_string(temp_time[3]);
            
            return latest_time;

        }

    }
};
