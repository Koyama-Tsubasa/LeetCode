class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        // parameters
        int removed_set_num = 0;
        std::unordered_map<int, int> IntSize;
        std::priority_queue<std::pair<int, int>> IntSetSize;

        // start computing
        // calculate the size of each integer & order them
        for (auto &n: arr) IntSize[n]++;
        for (auto &[Int, Size]: IntSize) IntSetSize.push({Size, Int});

        // removing them iteratively
        int total_size = arr.size();
        int removed_size = 0;
        while (removed_size < total_size/2) {

            removed_set_num++;
            removed_size += IntSetSize.top().first;
            IntSetSize.pop();

        }

        return removed_set_num;

    }
};
