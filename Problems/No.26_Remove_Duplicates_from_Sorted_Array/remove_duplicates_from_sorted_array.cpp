class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int index = 1;      // the current index
        int RDA_size = 1;   // the size of remove duplicates array
        
        // start compute
        while (index<nums.size()) {
            
            // check if the numner is different from the previous one
            if (nums[index-1] != nums[index]) nums[RDA_size++] = nums[index];
            index++;
        
        }
        
        return RDA_size;
        
    }
};
