class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        // parameter
        int min_gap = INT_MAX;

        // start computing
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-k+1; i++) 
            min_gap = std::min(min_gap, nums[i+k-1]-nums[i]);
        
        return min_gap;

    }
};
