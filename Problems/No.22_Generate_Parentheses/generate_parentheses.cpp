class Solution {
public:
    
    // backtracking function
    void DFS(vector<string>& GP, string str, int open, int close, int n) {
        
        // check if the size is valid
        if (str.length() == 2*n) {
            
            // push the answer
            GP.push_back(str);
            return;
            
        }
        
        // if the open branket is less than n then new branch
        if (open < n) DFS(GP, str+"(", open+1, close, n);
        
        // if the close branket is less than open branket then new branch
        if (close < open) DFS(GP, str+")", open, close+1, n);
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> GP_ans;
        
        // start compute (DFS backtracking method)
        DFS(GP_ans, "", 0, 0, n);
        return GP_ans;
        
    }
};
