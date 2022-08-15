class Solution {
public:
    bool isPalindrome(string s) {
        
        // parameters
        int front = 0;
        int end = s.length()-1;
        
        // start compute
        while (front < end) {
            
            if (!isalpha(s[front]) and !isdigit(s[front])) front++;
            else if (!isalpha(s[end]) and !isdigit(s[end])) end--;
            else if (tolower(s[front++]) != tolower(s[end--])) return false;
            
        }
        
        return true;
        
    }
};
