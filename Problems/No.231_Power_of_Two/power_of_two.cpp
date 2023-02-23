class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // check if it is negative or not
        if (n < 0) return false;

        // convert into bitset and check if the number of 1 bit is only 1
        std::bitset<32> Tbits(n);
        return true ? (Tbits.count() == 1) : false;

    }
};
