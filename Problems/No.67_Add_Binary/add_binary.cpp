class Solution {
public:
    string addBinary(string a, string b) {
        
        // store some parameters
        string AB_ans = "";
        int len_a = a.length() - 1, len_b = b.length() - 1;
        int carry = 0;
        
        // start compute
        while (len_a >= 0 or len_b >= 0 or carry) {
            
            if (len_a >= 0 and a[len_a--] == '1') carry++;
            if (len_b >= 0 and b[len_b--] == '1') carry++;
            AB_ans.insert(0, (carry % 2) ? "1" : "0");
            carry /= 2;
            
        }
        
        return AB_ans;
        
    }
};
