class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        // parameters
        std::unordered_map<int, std::pair<int, long long>> num_count_sum;
        std::vector<long long> SoD(nums.size(), 0);

        // start computing
        for (int i=0; i<nums.size(); i++) {

            num_count_sum[nums[i]].first++;
            num_count_sum[nums[i]].second += i;

        }
        
        // calculate the distances
        std::unordered_map<int, std::pair<int, long long>> partial_NCS;
        for (long long i=0; i<nums.size(); i++) {

            int num = nums[i];
            auto [total_count, total_sum] = num_count_sum[num];
            
            partial_NCS[num].first++;
            partial_NCS[num].second += i;
            auto [left_count, left_sum] = partial_NCS[num];

            // ans for index i will be i * leftSize - prefixSum of left side + prefixSum of right side - i * rightSize
            SoD[i] = i*(2*left_count - total_count) - (2*left_sum - total_sum);

        } 

        return SoD;

    }
};
