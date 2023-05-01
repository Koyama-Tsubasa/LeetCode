class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        // parameters
        int count = 0;
        int num_size = nums.size();

        // start computing
        for (int i=0; i<num_size; i++) {

            int j = i + 1;
            int k = num_size - 1;
            while (j < k) {
                
                int ij_diff = nums[j] - nums[i];
                int jk_diff = nums[k] - nums[j];

                if (ij_diff == diff) {

                    if (jk_diff == diff) {

                        count++;
                        break;

                    }
                    else if (jk_diff < diff) break;
                    else k--;

                }
                else if (ij_diff > diff) break;
                else j++;

            }

        }

        return count;

    }
};
