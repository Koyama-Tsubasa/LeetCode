class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // parameters
        int max = nums[0];  // store the maximum subarray value
        int r = nums[0];    // store the contiguous maximal subarray value

        // start compute
        for (int i=1; i<nums.size(); i++) {

            // calculate the partial maximal sum (max{nums[i], r+nums[i]})
            if (r+nums[i] < nums[i]) r = nums[i];
            else r += nums[i];

            // update the maximum sum
            if (r > max) max = r;

        }

        return max;

    }
};
