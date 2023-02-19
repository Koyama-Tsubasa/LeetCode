class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // preprocessing
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end());

        // parameter
        int j = 0;
        std::vector<vector<int>> new_intervals;

        // start computing
        new_intervals.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {

            if (new_intervals[j][1] >= intervals[i][0]) new_intervals[j][1] = max(new_intervals[j][1], intervals[i][1]);
            else {

                new_intervals.push_back(intervals[i]);
                j++;

            }

        }

        return new_intervals;

    }
};
