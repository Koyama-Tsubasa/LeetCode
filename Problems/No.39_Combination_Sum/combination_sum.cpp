class Solution {
public:
    
    // using backtracking
    void backtracking(vector<int>& candidates, int id, int target, vector<int>& temp, vector<vector<int>>& combinations) {
        
        // check for each case
        if ((target<0) or (id==candidates.size())) return;
        else if (target == 0) {
            
            combinations.push_back(temp);
            return;
            
        }
        else {
            
            // cases of involving this num or not
            temp.push_back(candidates[id]);
            backtracking(candidates, id, target-candidates[id], temp, combinations);
            temp.pop_back();
            backtracking(candidates, id+1, target, temp, combinations);
            
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        // parameters
        vector<int> temp;
        vector<vector<int>> combinations;
        
        // start compute
        backtracking(candidates, 0, target, temp, combinations);
        
        return combinations;
        
    }
};
