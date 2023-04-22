class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        // parameters
        long long temp_sum = 0;
        long long MAX_sum = 0;
        std::unordered_map<int, int> distinct_num_count;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            distinct_num_count[nums[i]]++;
            temp_sum += nums[i];
            
            if (i < k-1) continue;
            else {

                if (distinct_num_count.size() == k)
                    MAX_sum = std::max(MAX_sum, temp_sum);
                
                int substract = nums[i-k+1];
                temp_sum -= substract;

                if (distinct_num_count[substract] == 1) distinct_num_count.erase(substract);
                else distinct_num_count[substract]--;

            }

        }

        return MAX_sum;

    }
};
