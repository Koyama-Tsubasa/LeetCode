class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // parameter
        std::unordered_map<int, int> Nmapping;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            if ((Nmapping.find(nums[i]) != Nmapping.end()) && 
                (i-Nmapping[nums[i]] <= k)) return true;
            Nmapping[nums[i]] = i;

        }

        return false;

    }
};
