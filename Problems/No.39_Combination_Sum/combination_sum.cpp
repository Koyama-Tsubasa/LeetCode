class Solution {
public:
    
    // using back propagation
    void back_propagate(vector<int>& candidates, int id, int target, vector<int>& temp, vector<vector<int>>& combinations) {
        
        // check for each case
        if ((target<0) or (id==candidates.size())) return;
        else if (target == 0) {
            
            combinations.push_back(temp);
            return;
            
        }
        else {
            
            // cases of involving this num or not
            temp.push_back(candidates[id]);
            back_propagate(candidates, id, target-candidates[id], temp, combinations);
            temp.pop_back();
            back_propagate(candidates, id+1, target, temp, combinations);
            
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        // parameters
        vector<int> temp;
        vector<vector<int>> combinations;
        
        // start compute
        back_propagate(candidates, 0, target, temp, combinations);
        
        return combinations;
        
    }
};
