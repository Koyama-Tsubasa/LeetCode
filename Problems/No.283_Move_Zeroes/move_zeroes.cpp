class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // parameters
        int pSwap = 0;

        // start computing
        for (int i=0; i<nums.size(); i++) 
            if (nums[i] != 0) std::swap(nums[pSwap++], nums[i]);

    }
};
