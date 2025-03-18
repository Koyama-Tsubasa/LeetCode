class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bit_used=0, lft=0, max_length=0;

        for (int rht=0; rht<nums.size(); rht++) {

            while ((bit_used & nums[rht]) != 0) {
                bit_used ^= nums[lft];
                lft++;
            }
            bit_used |= nums[rht];
            max_length = max(max_length, rht-lft+1);

        }

        return max_length;

    }
};
