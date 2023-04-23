class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        // parameter
        int subarray_start = 0;
        int temp_count = 0;
        int nice_count = 0;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            if (nums[i]%2 == 1) {

                k--;
                if (k <= 0) {

                    temp_count = 1;
                    while (nums[subarray_start++]%2 == 0) temp_count++;
                    nice_count += temp_count;    

                }

            }
            else nice_count += temp_count;

        }

        return nice_count;

    }
};
