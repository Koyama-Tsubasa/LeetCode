class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        // mapping from digit to letters
        map<char, string> DL_mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> LCoaPN_ans;
        int temp_i;
        string temp_s;
        
        // start compute
        for (int c=0; c<digits.length(); c++) {
            
            temp_s = DL_mapping[digits[c]];
            
            // check if it is the first digit
            if (LCoaPN_ans.empty()) {
                
                for (int n=0; n<temp_s.length(); n++) {
                    
                    string s(1, temp_s[n]);
                    LCoaPN_ans.push_back(s);
                    
                }
                
            }
            else {
                
                temp_i = LCoaPN_ans.size();
                for (int e=0; e<temp_i; e++) {
                    
                    for (int n=0; n<temp_s.length(); n++) LCoaPN_ans.push_back(LCoaPN_ans[0]+temp_s[n]);
                    LCoaPN_ans.erase(LCoaPN_ans.begin());
                    
                }
                
            }
            
        }
        
        return LCoaPN_ans;
        
    }
};
