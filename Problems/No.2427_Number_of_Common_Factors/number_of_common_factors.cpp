class Solution {
public:
    int commonFactors(int a, int b) {
        
        // parameter
        int CF_cnt = 1;

        // start computing
        for (int i=2; i<=std::min(a, b); i++) 
            if ((a%i == 0) && (b%i == 0)) CF_cnt++;

        return CF_cnt;

    }
};
