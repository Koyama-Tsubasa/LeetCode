class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        // parameters
        std::vector<int> MS_Sequence;
        std::priority_queue<int> Heap;
        std::map<int, int> LargestSum;

        // start computing
        // create MAX-Heap
        for (auto &num: nums) Heap.push(num);

        // find largest sum
        for (int i=0; i<k; i++) {

            LargestSum[Heap.top()]++;
            Heap.pop();

        }

        // push in original order
        for (auto &num: nums) {
            if (LargestSum[num] > 0) {

                MS_Sequence.push_back(num);
                LargestSum[num]--;

            }
        }

        return MS_Sequence;

    }
};
