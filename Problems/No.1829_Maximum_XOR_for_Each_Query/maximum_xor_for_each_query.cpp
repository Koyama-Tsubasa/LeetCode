class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        // parameters
        int update_location = nums.size() - 1;
        int previous_xor = 0;
        const int MAX_k = (1<<maximumBit) - 1;
        std::vector<int> MAX_XOR(nums.size(), 0);

        // start computing
        for (auto &num: nums) {

            previous_xor ^= num;
            MAX_XOR[update_location--] = previous_xor ^ MAX_k;

        }

        return MAX_XOR;

    }
};
