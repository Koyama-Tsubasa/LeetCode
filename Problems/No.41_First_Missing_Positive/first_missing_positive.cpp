class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // parameters
        int i = 0;
        int sizeN = nums.size();

        // start computing
        while (i < sizeN) {

            if ((0 < nums[i]) && (nums[i] <= sizeN) && 
                (nums[nums[i]-1] != nums[i])) std::swap(nums[nums[i]-1], nums[i]);
            else i++;

        }

        for (int i=0; i<sizeN; i++) if (nums[i] != i+1) return i+1;
        return sizeN+1;

    }
};
