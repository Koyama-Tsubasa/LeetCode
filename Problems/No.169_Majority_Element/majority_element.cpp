class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // parameters
        int ans;
        int obj = nums.size()/2;
        map<int, int> counter;
        
        // start compute
        for (int i=0; i<nums.size(); i++) counter[nums[i]]++;
        for (auto m : counter) {
            if (m.second > obj) {
                
                ans = m.first;
                break;
                
            }
        }
        
        return ans;
        
    }
};
