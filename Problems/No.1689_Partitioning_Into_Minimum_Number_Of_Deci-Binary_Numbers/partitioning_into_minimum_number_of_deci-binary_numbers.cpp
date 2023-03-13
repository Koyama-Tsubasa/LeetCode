class Solution {
public:
    int minPartitions(string n) {
        
        // parameter
        int max_deci = 0;

        // start computing
        for (auto d: n) max_deci = std::max(max_deci, d-'0');

        return max_deci;

    }
};
