class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        // parameters
        long long SquaredDifference = 0;
        long long gaps = 0;
        int modification = k1 + k2;
        std::priority_queue<std::pair<int, int>> MAX_Heap;
        std::map<int, int> gapNum_mapping;

        // start computing
        // create MAX-Heap from the gap of two vectors
        for (int i=0; i<nums1.size(); i++) {

            auto cal_gap = std::abs(nums1[i]-nums2[i]);
            if (cal_gap > 0) {

                gapNum_mapping[cal_gap]++;
                gaps += cal_gap;

            }

        }
        for (auto gap_num: gapNum_mapping)
            MAX_Heap.push({gap_num.first, gap_num.second});

        // check if the gap can be eliminated
        if (gaps <= modification) return 0;
        else {

            // modify the nums for several times
            while ((modification > 0) && !MAX_Heap.empty()) {
                
                int gap1, gap2, num1, num2;
                gap1 = MAX_Heap.top().first;
                num1 = MAX_Heap.top().second;
                MAX_Heap.pop();

                if (!MAX_Heap.empty()) {

                    gap2 = MAX_Heap.top().first;
                    num2 = MAX_Heap.top().second;

                }
                else {

                    gap2 = gap1;
                    num2 = num1;

                }
                
                // if it is the last gap
                if (MAX_Heap.empty() || ((gap1-gap2)*num1 > modification)) {

                    int modify_each = modification / num1;
                    int modify_advanced = modification % num1;

                    MAX_Heap.push({gap1-modify_each, num1-modify_advanced});
                    MAX_Heap.push({gap1-modify_each-1, modify_advanced});

                    break;

                }
                else {

                    MAX_Heap.pop();
                    MAX_Heap.push({gap2, num1+num2});
                    modification -= ((gap1-gap2)*num1);

                }

            }

            // calculate the minimum square difference
            while (!MAX_Heap.empty()) {

                auto [gap, num] = MAX_Heap.top();
                SquaredDifference += (std::pow(gap, 2)*num);
                MAX_Heap.pop();

            }

            return SquaredDifference;

        }

    }
};
