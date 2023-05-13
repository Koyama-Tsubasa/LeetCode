class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        // parameters
        std::vector<int> DP(nums.size(), 1);
        std::vector<int> LIS_cnt(nums.size(), 1);
        int MAX_LIS = 1;
        int MAX_LIS_cnt = 0;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            for (int j=0; j<i; j++) 
                if (nums[j] < nums[i]) 
                    if (DP[i] < (DP[j] + 1)) {

                        DP[i] = DP[j] + 1;
                        LIS_cnt[i] = LIS_cnt[j];

                    }
                    else if ((DP[j] + 1) == DP[i]) LIS_cnt[i] += LIS_cnt[j];
            
            MAX_LIS = std::max(MAX_LIS, DP[i]);

        }

        for (int idx=0; idx<nums.size(); idx++)
            if (DP[idx] == MAX_LIS) MAX_LIS_cnt += LIS_cnt[idx];

        return MAX_LIS_cnt;

    }
};
