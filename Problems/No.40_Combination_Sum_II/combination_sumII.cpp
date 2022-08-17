class Solution {
public:
    // using backtracking
    void backtracking(vector<int>& candidates, int id, int target, vector<int>& temp, vector<vector<int>>& combinations) {
        
        // check for each case
        if (target == 0) combinations.push_back(temp);
        else if (target<0) return;
        else if (id<candidates.size() and candidates[id]>target) return;
            
        int prev = -1; 

        for(int j=id; j<candidates.size(); j++) {

            if(candidates[j] == prev) continue; // remove dublicate
            temp.push_back(candidates[j]);
            backtracking(candidates, j+1, target-candidates[j], temp, combinations);
            temp.pop_back(); 
            prev = candidates[j];

        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // parameters
        vector<int> temp;
        vector<vector<int>> combinations;
        
        // start compute
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target, temp, combinations);
        
        return combinations;
        
    }
};
