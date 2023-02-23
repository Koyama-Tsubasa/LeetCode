class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        // parameters
        std::vector<std::string> ranges;
        std::string temp;
        int range;

        // start computing
        for (int i=0; i<nums.size(); i++) {

            temp = std::to_string(nums[i]);
            for (range=1; range<nums.size()-i; range++)
                if (nums[i+range] != nums[i]+range) break;

            if (range == 1) ranges.push_back(temp);
            else {

                temp += ("->"+std::to_string(nums[i+range-1]));
                ranges.push_back(temp);
                i += (range-1);

            }

        }

        return ranges;

    }
};
