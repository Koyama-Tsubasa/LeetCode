class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // parameter
        int ans = 0;

        // start computing
        // reference: https://reurl.cc/n7OAXv
        for (auto num: nums) {

            if (ans < 2) ans++;
            else if (nums[ans-2] < num) nums[ans++] = num;

        }

        return ans;

    }
};
