class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // convert uint32_t into bitset followed by string
        std::bitset<32> bits(n);
        std::string bitString = bits.to_string();
        
        // reverse the string
        std::reverse(bitString.begin(), bitString.end());

        // convert string into bitset followed by uint32_t
        std::bitset<32> bits_reversed(bitString);
        uint32_t reversed_uint32_t = bits_reversed.to_ulong();

        return reversed_uint32_t;

    }
};
