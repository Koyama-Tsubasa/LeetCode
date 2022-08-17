class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // parameter
        int ans = 0;
        
        // start compute, using XOR
        for (auto num : nums) ans ^= num;
        
        return ans;
        
    }
};
