class Solution {
public:
    int reverse(int x) {
        
        // INT_MAX ...  2147483647
        // INT_MIN ... -2147483648
        
        int RI_ans = 0;
        int temp;
        
        // start compute
        while (x != 0) {

            temp = x%10;
            
            // check whether the value overflow
            if (((RI_ans > 214748364) or 
                 ((RI_ans == 214748364) and (temp >= 7))) or
                ((RI_ans < -214748364) or 
                 ((RI_ans == -214748364) and (temp >= 8)))) return 0;
            else RI_ans = RI_ans*10 + temp;
            
            x /= 10;

        } 
        
        return RI_ans;
        
    }
};
