class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // parameters
        int swap_h, swap_nh;
    
        // find the number which can be swapped 
        for (swap_h=nums.size()-2; swap_h>=0; swap_h--)
            if (nums[swap_h] < nums[swap_h+1]) break;         
        
        // check if the given is in decreasing order
        if (swap_h == -1) reverse(nums.begin(), nums.end());
        else {
            
            // find the number which to swapped, becomes the new sub_header
            for (swap_nh=nums.size()-1; swap_nh>swap_h; swap_nh--) 
                if (nums[swap_nh] > nums[swap_h]) break;
            
            // swap the found two numbers and sort the numbers after sub_header
            swap(nums[swap_h], nums[swap_nh]);
            sort(nums.begin()+swap_h+1, nums.end());
                
        }
        
    }
};
