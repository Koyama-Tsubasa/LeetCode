class Solution {
	private:
        
        // find all permutations using backtracking
        void solve(int idx,vector<int> nums,vector<vector<int>>& ans){

            if(idx == nums.size()){

                ans.push_back(nums);
                return;

            }
            else {
                
                for(int i = idx; i < nums.size(); i++){

                    //avoid duplicates
                    if(i!=idx && nums[i]==nums[idx]) continue;
                    else {

                        swap(nums[i], nums[idx]);
                        solve(idx+1, nums, ans);

                    }

                }                
                
            }

        }

	public:
    
		vector<vector<int>> permuteUnique(vector<int>& nums) {
            
            // parameter
			vector<vector<int>> all_permutations;
            
            // start compute, using backtracking
			sort(nums.begin(),nums.end());
			solve(0, nums, all_permutations);
            
			return all_permutations;
            
		}
};
