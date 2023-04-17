class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        // parameter
        int target_threshold = k*threshold;
        int k_sum = 0;
        int cleared_subarrays = 0;
        
        // start computing
        for(int i=0; i<arr.size(); i++) {

            k_sum += arr[i];
            if (i < k-1) continue;
            else {
                
                if (k_sum >= target_threshold) cleared_subarrays++;
                k_sum -= arr[i-k+1];

            }

        }

        return cleared_subarrays;

    }
};
