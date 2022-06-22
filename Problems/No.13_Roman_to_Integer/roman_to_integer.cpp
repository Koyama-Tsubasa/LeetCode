class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> Roman_table;   // table of Romans
        int cur = 0;                  // save current partial Roman integer
        int pre = 0;                  // save previous partial Roman integer
        int output = 0;               // calculate the output
        
        // construct Roman table
        Roman_table['I'] = 1;
        Roman_table['V'] = 5;
        Roman_table['X'] = 10;
        Roman_table['L'] = 50;
        Roman_table['C'] = 100;
        Roman_table['D'] = 500;
        Roman_table['M'] = 1000;
        
        // start compute
        for (int i=0; i<s.length(); i++) {
            
            cur = Roman_table[s[i]];
            
            // check whether the subtraction is used or not
            if (pre < cur) output = output-2*pre+cur;
            else output += cur;
            pre = cur;
            
        }
        
        return output;
        
    }
};
