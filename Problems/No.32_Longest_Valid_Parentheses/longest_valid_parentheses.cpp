class Solution {
public:
    int longestValidParentheses(string s) {
        
        // parameters
        int ans = 0;
        int open_blacket, close_blacket;
        
        // start compute
        // left to right but cannot check the patterns like "(()"
        open_blacket = 0;
        close_blacket = 0;
        for (int c=0; c<s.length(); c++) {
            
            if (s[c] == '(') open_blacket++;
            else close_blacket++;
            
            if (open_blacket == close_blacket) ans = max(ans, 2*open_blacket);
            else if (close_blacket > open_blacket){
                
                open_blacket = 0;
                close_blacket = 0;
                
            }
            
        }
        
        // right to left but cannot check the patterns like "())"
        open_blacket = 0;
        close_blacket = 0;
        for (int c=s.length()-1; c>=0; c--) {
            
            if (s[c] == ')') close_blacket++;
            else open_blacket++;
            
            if (open_blacket == close_blacket) ans = max(ans, 2*close_blacket);
            else if (close_blacket < open_blacket){
                
                open_blacket = 0;
                close_blacket = 0;
                
            }
            
        }
        
        return ans;
        
    }
};
