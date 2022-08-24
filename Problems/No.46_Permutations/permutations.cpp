class Solution {
public:
    
    // find all permutations using backtracking
    void solve(vector<int> &permutation, vector<vector<int>> &all_permutations, int index, int max) {
        
        if (index >= max) {
            
            all_permutations.push_back(permutation);
            return;
            
        }
        else {
            
            for (int i=index; i<max; i++) {
                
                swap(permutation[index], permutation[i]);
                solve(permutation, all_permutations, index+1, max);
                swap(permutation[index], permutation[i]);
                
            }
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> all_permutations;   // parameter
        solve(nums, all_permutations, 0, nums.size());  // start compute, using backtracking
        return all_permutations;
        
    }
};
