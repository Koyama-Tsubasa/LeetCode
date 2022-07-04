class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // position of the current index
        int cur_index = 0;
        
        // start compute
        while (cur_index != nums.size()) {
            
            if (nums[cur_index] == val) nums.erase(nums.begin()+cur_index);
            else cur_index++;
            
        }
        
        return cur_index;
        
    }
};
