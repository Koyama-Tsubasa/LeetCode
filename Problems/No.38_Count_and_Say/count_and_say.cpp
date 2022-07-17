class Solution {
public:
    string countAndSay(int n) {
        
        // parameters
        int i = 0, cnt;
        string s;
        string CaS_ans = "";
        
        // start compute
        if (n == 1) return "1";
        else {
            
            // first return the previous answer
            s = countAndSay(n-1);
            
            // start counting
            while (i < s.length()) {
                
                cnt = 1;
                while (i<s.length() and s[i]==s[i+1]) {
                    
                    i++;
                    cnt++;
                    
                }
                CaS_ans += to_string(cnt) + s[i++];
                
            }
            
        }
        
        return CaS_ans;
        
    }
};
