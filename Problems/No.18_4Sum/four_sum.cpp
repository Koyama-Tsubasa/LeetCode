class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // store some parameters
        long target_3sum, target_2sum;
        int nums_len = nums.size();
        int l_index, r_index;
        vector<vector<int>> fS_ans;
        
        // preprocess
        if (nums_len < 4) return fS_ans;
        
        // start compute
        sort(nums.begin(), nums.end());
        for (int first=0; first<nums_len-3; first++) {
            
            // remove duplicates
            if (first>0 and nums[first]==nums[first-1]) continue;
                
            // do 3Sum
            target_3sum = target - nums[first];
            for (int tS=first+1; tS<nums_len-2; tS++) {

                // remove duplicates
                if (tS>first+1 and nums[tS]==nums[tS-1]) continue;
                
                target_2sum = target_3sum - nums[tS];
                l_index = tS + 1;
                r_index = nums_len - 1;

                while (l_index < r_index) {

                    if (nums[l_index] + nums[r_index] < target_2sum) l_index++;
                    else if (nums[l_index] + nums[r_index] > target_2sum) r_index--;
                    else {

                        // found the target
                        fS_ans.push_back({nums[first], nums[tS], nums[l_index], nums[r_index]});
                        
                        // remove duplicates
                        auto l_same = nums[l_index], r_same = nums[r_index];
                        while (l_index<r_index and nums[l_index]==l_same) l_index++;
                        while (l_index<r_index and nums[r_index]==r_same) r_index--;

                    }

                }   
                    
            }      
                
        }
        
        return fS_ans;
        
    }
};
