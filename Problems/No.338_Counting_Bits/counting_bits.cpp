class Solution {
public:
    vector<int> countBits(int n) {
        
        // parameter
        std::vector<int> binaryBits(n+1, 0);

        // start computing
        for (int i=1; i<=n; i++) 
            binaryBits[i] = binaryBits[i/2] + i%2;
        
        return binaryBits;

    }
};
