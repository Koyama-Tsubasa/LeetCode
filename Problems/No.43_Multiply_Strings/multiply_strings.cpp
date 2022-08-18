class Solution {
public:
    string multiply(string num1, string num2) {
        
        // parameters
        int num1_len = num1.length();
        int num2_len = num2.length();
        int product;
        string ans;
        
        // start compute
        if ((num1_len==1 and num1[0]=='0') or (num2_len==1 and num2[0]=='0')) return "0";
            
        for (int i=0; i<num1_len+num2_len; i++) ans += "0";
        for (int i=num1_len-1; i>=0; i--) {
            for (int j=num2_len-1; j>=0; j--) {

                product = (num1[i]-'0')*(num2[j]-'0');
                product += ans[i+j+1]-'0';
                ans[i+j+1] = product%10 + '0';
                ans[i+j] = ans[i+j] + product/10;

            }
        }
        
        for (int i=0; i<num1_len+num2_len; i++) if (ans[i]!='0') return ans.substr(i);
        return "0";
        
    }
};
