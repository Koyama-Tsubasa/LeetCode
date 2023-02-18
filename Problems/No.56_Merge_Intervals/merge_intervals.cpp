class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // parameters
        std::vector<std::vector<int>> merged_intervals;

        // start computing
        std::sort(intervals.begin(), intervals.end());
        for (auto interval: intervals) {

            if (merged_intervals.empty() || merged_intervals.back()[1] < interval[0])
                merged_intervals.push_back(interval);
            else merged_intervals.back()[1] = std::max(merged_intervals.back()[1], interval[1]);

        }

        return merged_intervals;

    }
};
