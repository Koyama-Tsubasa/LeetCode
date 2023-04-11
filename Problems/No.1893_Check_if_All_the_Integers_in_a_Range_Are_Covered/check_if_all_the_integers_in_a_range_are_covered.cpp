class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        // parameter
        std::vector<bool> check_range(right-left+1, false);

        // start computing
        for (auto &range: ranges) {

            int rangeL = range[0];
            int rangeR = range[1];
            for (int i=std::max(rangeL, left); i<=std::min(rangeR, right); i++)
                check_range[i-left] = true;

        }

        for (auto check_int: check_range) if (!check_int) return false;
        return true;

    }
};
