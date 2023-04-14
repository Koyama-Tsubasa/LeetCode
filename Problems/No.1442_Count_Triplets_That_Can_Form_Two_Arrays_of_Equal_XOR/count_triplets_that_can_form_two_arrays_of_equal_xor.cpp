class Solution {
public:
    int countTriplets(vector<int>& arr) {

	// parameter
        int triplet_count = 0;
	std::unordered_map<int, std::vector<int>> xor_idx;

        // start computing
        int xor_sum = 0;
        xor_idx[0].push_back(-1);
        for (int i=0; i<arr.size(); i++) {

            xor_sum ^= arr[i];
            if (xor_idx.find(xor_sum) != xor_idx.end())
                for (auto &idx: xor_idx[xor_sum])
                    triplet_count += i-idx-1;
            xor_idx[xor_sum].push_back(i);

        }

        return triplet_count;

    }
};
