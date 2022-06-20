class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i;
        map<int, int> find_solution;    // map of nums[i] -> i
        
        // iterate the whole array once
        for (i=0; i<nums.size(); i++) {
            
            // if find out the solution then break, else insert new key -> index
            if (find_solution.find(target-nums[i]) != find_solution.end()) break;
            else find_solution[nums[i]] = i;
            
        }
        
        vector<int> solution = {find_solution[target-nums[i]], i};
        return solution;
    }
};
