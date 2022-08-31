class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        // parameter
        string ans = "";
        
        // start compute
        columnNumber--;
        while (columnNumber >= 0) {
            
            ans = char(65+columnNumber%26) + ans;
            columnNumber /= 26;
            columnNumber--;
            
        }
        
        return ans;
        
    }
};
