class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // parameter
        std::unordered_set<int> num_set;

        // start computing
        for (auto num: nums) {

            if (num_set.find(num) != num_set.end()) return true;
            else num_set.insert(num);

        }
        
        return false;

    }
};
