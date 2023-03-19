class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        // parameter
        int operations = 0;

        // start computing
        for (int i=1; i<nums.size(); i++) 
            if (nums[i-1] >= nums[i]) {

                operations += (nums[i-1] -nums[i] + 1);
                nums[i] = nums[i-1] + 1;

            }
        
        return operations;

    }
};
