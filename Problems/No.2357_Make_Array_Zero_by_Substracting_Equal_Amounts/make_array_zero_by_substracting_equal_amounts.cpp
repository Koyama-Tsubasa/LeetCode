class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        // parameter
        std::unordered_set<int> numSet;

        // start computing
        for (auto &num: nums) 
            if ((num > 0) && (numSet.count(num) == 0)) 
                numSet.insert(num);
        
        return numSet.size();

    }
};
