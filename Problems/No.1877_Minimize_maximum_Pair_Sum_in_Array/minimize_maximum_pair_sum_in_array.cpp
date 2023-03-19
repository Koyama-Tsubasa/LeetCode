class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        // parameter
        int max_PS = 0;

        // start computing
        std::sort(nums.begin(), nums.end());
        for (int i=0, j=nums.size()-1; i<j; i++, j--) max_PS = std::max(max_PS, nums[i]+nums[j]);

        return max_PS;

    }
};
