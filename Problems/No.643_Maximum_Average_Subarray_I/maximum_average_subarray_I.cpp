class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        // parameters
        double max_sum = INT_MIN;
        double partial_sum = 0;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            partial_sum += nums[i];
            if (i < k-1) continue;
            
            max_sum = std::max(max_sum, partial_sum);
            partial_sum -= nums[i-k+1];

        }
        
        return max_sum/k;

    }
};
