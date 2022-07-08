class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // check if the carry occurs
        bool carry = 0;
        
        // start compute
        for (int i=digits.size()-1; i>=0; i--) {
            
            digits[i] += 1;
            if (digits[i] >= 10) {
                
                carry = 1;
                digits[i] -= 10;
                
            }
            else {
                
                carry = 0;
                break;
                
            }
            
        }
        
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
        
    }
};
