class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int flip_cnt = 0, nums_size=nums.size()-1;

        for (int i=0; i<=nums_size-2; i++) {

            if (nums[i] == 1) continue;
            for (int flip=i; flip<i+3; flip++) nums[flip] ^= 1;
            flip_cnt ++;

        }

        if (nums[nums_size] && nums[nums_size-1]) return flip_cnt;
        else return -1;

    }
};
