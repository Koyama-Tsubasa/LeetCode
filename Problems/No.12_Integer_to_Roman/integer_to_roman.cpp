class Solution {
public:
    string intToRoman(int num) {
        
        // create the list of integer-to-roman
        int integer[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ItR_ans = "";
        
        // start compute
        for (int i=0; i<sizeof(integer)/sizeof(*integer); i++) {
            
            while (integer[i] <= num) {
                
                num -= integer[i];
                ItR_ans += rom[i];
                
            }
            
        }
        
        return ItR_ans;
        
    }
};
