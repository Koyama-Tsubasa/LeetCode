class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        // parameter
        std::vector<int> LRDifference(nums.size()+1, 0);

        // start computing
        std::partial_sum(nums.begin(), nums.end(), LRDifference.begin()+1);
        for (int i=0; i<nums.size(); i++) 
            LRDifference[i] = std::abs(LRDifference.back() - LRDifference[i+1] - LRDifference[i]);
        LRDifference.pop_back();

        return LRDifference;

    }
};
