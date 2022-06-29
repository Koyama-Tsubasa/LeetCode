class Solution {
public:
    string longestPalindrome(string s) {
        
        int i, j;
        int s_length = s.length();
        int LPS_start = 0, LPS_length = 1;
        
        // using dynamic programming
        bool dp[s_length][s_length];
        memset(dp, 0, sizeof(dp));
        
        // case1: every single character is a palindrome
        for (i=0; i<s_length; i++)
            dp[i][i] = 1;
        
        // case2: check two characters at a time
        for (i=0; i<s_length-1; i++) {
            
            if (s[i] == s[i+1]) {
                
                dp[i][i+1] = 1;
                LPS_start = i;
                LPS_length = 2;
                
            }
            
        }
        
        // case3: characters more than 2
        // " dp[i][j] = dp[i+1][j-1] and (s[i] = s[j]) "
        for (int gap=2; gap<s_length; gap++) {
            for (i=0; i<s_length-gap; i++) {
                
                j = i + gap;
                if ((s[i] == s[j]) and dp[i+1][j-1]) {
                    
                    dp[i][j] = 1;
                    LPS_start = i;
                    LPS_length = gap + 1;
                    
                }
                
            }
        }
        
        return s.substr(LPS_start, LPS_length);
        
    }
};
