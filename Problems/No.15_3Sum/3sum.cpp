class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // store the pointers
        int zero, l_index, r_index;
        vector<vector<int>> threesum_ans;
        
        // preprocess
        if (nums.size() < 3) return threesum_ans;
        
        // start compute
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            
            // check if it violates the rules
            if (nums[i] > 0) break;
            else if (i == 0 or (i > 0 and (nums[i] != nums[i-1]))) {
                
                zero = -nums[i];
                l_index = i + 1;
                r_index = nums.size() - 1;

                while (l_index < r_index) {

                    if (nums[l_index] + nums[r_index] < zero) l_index++;
                    else if (nums[l_index] + nums[r_index] > zero) r_index--;
                    else {

                        threesum_ans.push_back({nums[i], nums[l_index], nums[r_index]});
                        while ((l_index < r_index) and (nums[l_index] == nums[l_index+1])) l_index++;
                        while ((l_index < r_index) and (nums[r_index-1] == nums[r_index])) r_index--;
                        l_index++;
                        r_index--;

                    }
                
                }
                
            }
            
        }
        
        return threesum_ans;
        
    }
};
