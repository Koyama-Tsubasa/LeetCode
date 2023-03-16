class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        // parameter
        long long appended_sum = 0;
        int added_num = 0;
        int i = 1;

        // start computing
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        
        while (k > 0) {

            // the case between two nums
            added_num = nums[i] - nums[i-1] - 1;
            if (added_num > 0) {
                
                added_num = std::min(added_num, k);
                appended_sum += ((nums[i-1]+1) + (nums[i-1]+added_num))*(long)added_num/2;
                k -= added_num;

            }
            i++;

            // the case after all nums
            if ((i >= nums.size()) && (k > 0)) {
                
                appended_sum += ((nums[nums.size()-1]+1) + (nums[nums.size()-1]+k))*(long)k/2;
                break;

            }

        }
        
        return appended_sum;

    }
};
