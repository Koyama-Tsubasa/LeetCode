class Solution {
public:
    int numDecodings(string s) {
        
        // parameters
        int s_length = s.length();
        std::vector<int> DP(s_length+1, 0);

        // start computing
        DP[0] = 1;
        for (int i=1; i<=s_length; i++) {

            if (s[i-1] != '0') DP[i] += DP[i-1];
            if ((1 < i) && ((s[i-2] == '1') || ((s[i-2] == '2') && (s[i-1] <= '6')))) 
                DP[i] += DP[i-2];

        }
        
        return DP[s_length];

    }
};
