class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // parameter
        std::bitset<1000> num_set;
        std::vector<int> intersection;

        // start computing
        for (auto num: nums1) num_set.set(num);
        for (auto num: nums2) {
            if (num_set[num]) {

                intersection.push_back(num);
                num_set.reset(num);

            }
        }

        return intersection;

    }
};
