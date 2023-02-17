class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // parameters
        int Mstep = 0;
        int sizeN = nums.size();

        // start computing
        for (int i=0; i<sizeN; i++) {

            if ((i > Mstep) || (Mstep >= sizeN-1)) break;
            else Mstep = max(Mstep, i+nums[i]);

        }

        if (Mstep >= sizeN-1) return true;
        else return false;

    }
};
