class Solution {
public:
    bool isPalindrome(string s) {
        
        // parameters
        int front = 0;
        int end = s.length()-1;
        
        // start compute
        while (front < end) {
            
            if (!isalnum(s[front])) front++;
            else if (!isalnum(s[end])) end--;
            else if (tolower(s[front++]) != tolower(s[end--])) return false;
            
        }
        
        return true;
        
    }
};
