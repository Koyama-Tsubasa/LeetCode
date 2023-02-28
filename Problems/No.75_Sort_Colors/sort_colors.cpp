class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // parameters
        int cur = 0;
        int left = 0;
        int right = nums.size() - 1;

        // start computing (use Dutch National Flag algorithm)
        while (cur <= right) 
            switch(nums[cur]) {

                case 0:
                    std::swap(nums[cur], nums[left]);
                    left++;
                    cur++;
                    break;

                case 1:
                    cur++;
                    break;

                case 2:
                    std::swap(nums[cur], nums[right]);
                    right--;
                    break;
                    
                default:
                    break;

            }

    }
};
