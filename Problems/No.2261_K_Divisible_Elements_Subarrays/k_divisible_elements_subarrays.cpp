class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        // parameters
        int dis_cnt = 0;
        std::unordered_set<std::string> dis_subarrays;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            int divisible = 0;
            std::string subarray = "";
            for (int j=i; j<nums.size(); j++) {

                if (nums[j]%p == 0) divisible++;
                if (divisible > k) break;
                subarray += (std::to_string(nums[j]) + "-");
                if (dis_subarrays.count(subarray) == 0) {

                    dis_cnt++;
                    dis_subarrays.insert(subarray);

                }

            }

        }

        return dis_cnt;

    }
};
