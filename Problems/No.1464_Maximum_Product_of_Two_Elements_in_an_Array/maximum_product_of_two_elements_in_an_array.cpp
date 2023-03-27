class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // start computing
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        return ((nums[0]-1) * (nums[1]-1));

    }
};
