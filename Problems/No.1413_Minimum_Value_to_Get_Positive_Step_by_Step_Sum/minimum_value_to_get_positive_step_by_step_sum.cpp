class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        // parameter
        int min_sum = INT_MAX;

        // start computing
        int sum = 0;
        for (auto &num: nums) {

            sum += num;
            min_sum = std::min(min_sum, sum);

        }

        return (min_sum < 1) ? std::abs(min_sum)+1 : 1;

    }
};
