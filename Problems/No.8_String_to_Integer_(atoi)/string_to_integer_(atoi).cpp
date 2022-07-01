class Solution {
public:
    int myAtoi(string s) {
        
        // ASCII code 48..."0", 57..."9"
        // INT_MAX ...  2147483647
        // INT_MIN ... -2147483648
        
        int c = 0;
        int StI_ans = 0;
        bool pos_neg = 0;
        
        // start compute
        // find until '-', '+', or digit appear
        while (c < s.length() and s[c] == ' ') c++;
        if (s[c] == '-' or s[c] == '+') {
            
            pos_neg = (s[c]=='-') ? 1 : 0;
            c++;
            
        }
        
        // compute the answer
        while (c < s.length() and 48 <= s[c] and s[c] <= 57) {
            
            int digit = s[c] - 48;
          
            // check whether it overflow or not
            if (!pos_neg and 
               ((StI_ans > 214748364) or 
                (StI_ans == 214748364) and (digit >= 7))) return INT_MAX;
            else if (pos_neg and
                    ((StI_ans > 214748364) or 
                     (StI_ans == 214748364) and (digit >= 8))) return INT_MIN;
            
            StI_ans = StI_ans*10 + digit;
            c++;
            
        }
        
        if (pos_neg) return -1*StI_ans;
        else return StI_ans;
        
    }
};
