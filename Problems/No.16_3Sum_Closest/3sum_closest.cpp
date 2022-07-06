class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // store some parameters
        int SC3_ans;
        int temp_sum;
        int diff = INT_MAX;
        int l_index, r_index;
        
        // start compute
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            
            // check if the set is contained in the last set
            if (i == 0 or (i > 0 and (nums[i] != nums[i-1]))) {
                
                l_index = i + 1;
                r_index = nums.size() - 1;
                while (l_index < r_index) {

                    temp_sum = nums[i] + nums[l_index] + nums[r_index];
                    if (temp_sum == target) return target;
                    else if (temp_sum < target) l_index++;
                    else r_index--;

                    // update the answer and the difference
                    if (abs(temp_sum-target) < diff) {

                        diff = abs(temp_sum-target);
                        SC3_ans = temp_sum;

                    }

                }   
                
            }
            
        }
        
        return SC3_ans;
        
    }
};
