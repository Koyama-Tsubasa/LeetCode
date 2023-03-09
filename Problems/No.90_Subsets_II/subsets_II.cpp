class Solution {
public:

    // create subset under corresponding size
    void create_subsets(int start, int end, int size, std::vector<int> &set, std::vector<int> &subset, std::vector<std::vector<int>> &subsets) {

        if (subset.size() == size) subsets.push_back(subset);
        else {

            for (int i=start; i<=end; i++) {

                // remove duplicate
                if ((i>start) && (set[i] == set[i-1])) continue;

                subset.push_back(set[i]);
                create_subsets(i+1, end, size, set, subset, subsets);
                subset.pop_back();

            }

        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // parameter
        std::vector<std::vector<int>> subsets;
        std::vector<int> subset;
        int sizeN = nums.size();

        // start computing
        std::sort(nums.begin(), nums.end());
        subsets.push_back({});
        for (int i=1; i<=sizeN; i++) {

            create_subsets(0, sizeN-1, i, nums, subset, subsets);
            subset.clear();

        }

        return subsets;


    }
};
