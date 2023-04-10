class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        // parameters
        std::vector<int> LSum(nums.size()+1, 0);
        std::vector<int> LRDifference;

        // start computing
        std::partial_sum(nums.begin(), nums.end(), LSum.begin()+1);
        for (int i=0; i<nums.size(); i++) 
            LRDifference.push_back(std::abs(LSum.back() - LSum[i+1] - LSum[i]));

        return LRDifference;

    }
};
