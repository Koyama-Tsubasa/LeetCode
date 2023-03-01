class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // parameters
        int numS = nums.size();
        int missingN = (1+numS)*numS/2;

        // start computing
        for (auto num: nums) missingN -= num;

        return missingN;

    }
};
