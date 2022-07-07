class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int LoLW_ans = 0;
        int index = s.length() - 1;
        
        // start compute
        while (s[index] == ' ') index--;
        while (index >= 0 and s[index--] != ' ') LoLW_ans++;
        
        return LoLW_ans;
        
    }
};
