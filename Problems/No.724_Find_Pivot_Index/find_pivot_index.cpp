class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        // parameters
        int num_sum = 0;
        int left_sum = 0;
        int pivot_index = 0;

        // start computing
        for (auto &num: nums) num_sum += num;
        for (auto &num: nums) {

            num_sum -= num;
            if (num_sum == left_sum) return pivot_index;
            else pivot_index++;
            left_sum += num;

        }

        return -1;

    }
};
