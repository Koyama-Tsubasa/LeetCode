class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int strs_length = strs.size();  // the length of strs
        string result="";               // save the result
        sort(strs.begin(), strs.end()); // sort strs by alphabet order
        
        // start compute
        for (int i=0; i<strs[0].length(); i++) {
            
            // check whether the alphabet is all same in index i
            if (strs[0][i] == strs[strs_length-1][i]) result += strs[0][i];
            else break;
        }
        
        return result;
    }
};
