class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        // parameters
        int subarray_size = nums.size();
        int remainder = 0; 
        std::unordered_map<int, int> preSum_index;

        // start computing
        // check the remainder (need to remove)
        for (auto &num: nums) remainder = (remainder + num) % p;
        if (remainder == 0) return 0;
        else {

            int pre_sum = 0, find_gap;
            preSum_index[0] = -1;
            for (int i=0; i<nums.size(); i++) {

                pre_sum = (pre_sum + nums[i]) % p;
                preSum_index[pre_sum] = i;

                find_gap = (pre_sum - remainder + p) % p;
                if (preSum_index.find(find_gap) != preSum_index.end())
                    subarray_size = std::min(subarray_size, i-preSum_index[find_gap]);

            }

            return (subarray_size < nums.size()) ? subarray_size : -1;

        }

    }
};
