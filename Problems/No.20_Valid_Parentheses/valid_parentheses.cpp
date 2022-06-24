class Solution {
public:
    bool isValid(string s) {
        
        stack<char> STACK;  // the stack to save (, [, {
        char check;         // to check the top of the stack
        
        // start compute
        for (int i=0; i<s.length(); i++) {
            
            // check whether to push into the stack or pop out
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') STACK.push(s[i]);
            else {
                
                // check if the stack is empty while you are going to pop out
                if (STACK.empty()) return false;
                else {
                    
                    // check whether it is valid or not
                    check = STACK.top();
                    if ( not(s[i] == ')' and check == '(') and
                         not(s[i] == ']' and check == '[') and
                         not(s[i] == '}' and check == '{')) return false;
                    else STACK.pop();
                    
                }
                
            }
            
        }
        
        // check if the stack is empty when you finish iterating s
        return STACK.empty();
        
    }
};
