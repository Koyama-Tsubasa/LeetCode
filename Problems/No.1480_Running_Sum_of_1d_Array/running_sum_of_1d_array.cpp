class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        // parameter
        std::vector<int> Running_Sum(nums.size(), 0);

        // start computing
        std::partial_sum(nums.begin(), nums.end(), Running_Sum.begin());

        return Running_Sum;

    }
};
