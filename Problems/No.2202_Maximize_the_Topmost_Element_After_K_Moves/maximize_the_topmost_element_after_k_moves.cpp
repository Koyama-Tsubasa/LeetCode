class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        // parameter
        int max_value = 0;

        // start computing
        if ((nums.size() == 1) && (k%2 == 1)) return -1;
        else if (nums.size() < k) return *std::max_element(nums.begin(), nums.end());
        else {

            for (int i=0; i<k-1; i++) max_value = std::max(max_value, nums[i]);
            if (k < nums.size()) max_value = std::max(max_value, nums[k]);
            return max_value;

        }

    }
};
