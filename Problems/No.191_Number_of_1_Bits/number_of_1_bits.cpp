class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // convert uint32_t into bitset & count the number of 1s
        std::bitset<32> bit_string(n);
        return bit_string.count();

    }
};
