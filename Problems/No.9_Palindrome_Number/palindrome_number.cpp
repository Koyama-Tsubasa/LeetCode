class Solution {
public:
    bool isPalindrome(int x) {
        
        string x_string = to_string(x);   // change int to string
        int x_size = x_string.size();     // check the string size
        bool true_or_false = 1;           // return value
      
        // check if it is palindrome
        for (int i=0; i<x_size/2; i++) {
            if (x_string[i] != x_string[x_size-i-1]) {
                true_or_false = 0;
                break;
            }
        }
        if (true_or_false) return true;
        else return false;
        
    }
};
