class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // parameter
        std::unordered_map<int, int> num_set;
        std::vector<int> intersection;

        // start computing
        for (auto num: nums1) num_set[num]++;
        for (auto num: nums2) {
            if (num_set[num] > 0) {

                intersection.push_back(num);
                num_set[num]--;

            }
        }

        return intersection;

    }
};
