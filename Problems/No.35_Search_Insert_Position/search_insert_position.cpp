class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int SIP_ans;
        
        for (SIP_ans=0; SIP_ans<nums.size(); SIP_ans++) 
            if (nums[SIP_ans] >= target) break;
        return SIP_ans;
        
    }
};
