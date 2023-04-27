class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // reference:
        // https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/3068804/kadane-min-sum-subarray/

        // parameters
        int global_MAX = nums[0];
        int global_min = nums[0];
        int local_MAX = 0;
        int local_min = 0;
        int total_sum = 0;

        //  start computing (using modified Kadane's Algorithm)
        for (auto &num: nums) {

            total_sum += num;
            local_MAX = std::max(local_MAX + num, num);
            local_min = std::min(local_min + num, num);

            global_MAX = std::max(global_MAX, local_MAX);
            global_min = std::min(global_min, local_min);

        }

        return (global_MAX > 0) ? std::max(global_MAX, total_sum - global_min) : global_MAX;

    }
};
