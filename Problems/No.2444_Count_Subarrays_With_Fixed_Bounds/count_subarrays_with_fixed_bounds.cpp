class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        // parameters
        int min_found = -1, MAX_found = -1;
        int subarray_start = 0;
        long long SubArrayCount = 0;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            if ((nums[i] < minK) || nums[i] > maxK) {

                subarray_start = i + 1;
                min_found = MAX_found = -1;
                
            }
            else {

                if (nums[i] == minK) min_found = i;
                if (nums[i] == maxK) MAX_found = i;

                if ((min_found > -1) && (MAX_found > -1)) 
                    SubArrayCount += std::min(min_found, MAX_found) - subarray_start + 1;
                
            } 

        }

        return SubArrayCount;

    }
};
