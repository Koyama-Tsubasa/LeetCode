class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        // parameter
        std::vector<std::pair<int, int>> GP_times;
        int earliest_possible_day = 0, pT_sum = 0;

        // start computing
        for (int i=0; i<plantTime.size(); i++) GP_times.push_back(std::make_pair(growTime[i], plantTime[i]));
        std::sort(GP_times.rbegin(), GP_times.rend());
        for (auto [gT, pT]: GP_times) {

            pT_sum += pT;
            earliest_possible_day = std::max(earliest_possible_day, pT_sum+gT);

        }

        return earliest_possible_day;

    }
};
