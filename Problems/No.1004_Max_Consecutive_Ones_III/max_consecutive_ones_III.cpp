class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        // parameters
        int max_ones = 0;
        int start_idx = 0;

        // start computing
        for (int end_idx=0; end_idx<nums.size(); end_idx++) {

            if (nums[end_idx] == 0) k--;
            while (k < 0) if (nums[start_idx++] == 0) k++;
            max_ones = std::max(max_ones, end_idx - start_idx + 1);

        }

        return max_ones;

    }
};
