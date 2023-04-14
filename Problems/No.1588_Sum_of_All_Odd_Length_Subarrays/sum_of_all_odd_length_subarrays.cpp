class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        // parameters
        int OLS_sum;
        int arr_size = arr.size();
        std::vector<int> preSum(arr_size, 0);

        // start computing
        // calculate prefix sum
        std::partial_sum(arr.begin(), arr.end(), preSum.begin());

        // calculate the sum of subarrays from array size 3 (3, 5, 7, ...)
        OLS_sum = preSum[arr_size-1];
        for (int odd=2; odd<arr_size; odd += 2) {

            OLS_sum += preSum[odd];
            for (int i=odd+1; i<arr_size; i++)
                OLS_sum += preSum[i] - preSum[i-odd-1];

        }

        return OLS_sum;

    }
};
