class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        std::bitset<32> bit_string(n);
        return bit_string.count();

    }
};
