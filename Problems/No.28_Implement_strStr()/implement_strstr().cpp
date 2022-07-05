class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // store the current index of haystack and needle
        int h_index = 0;
        int n_index = 0;
        
        // start compute
        while (h_index < haystack.length()) {
            
            // if same then compare the next index else h_index++, n_index <- 0
            if (haystack[h_index] == needle[n_index]) {
                
                h_index++;
                n_index++;
                
            }
            else {
                
                h_index = h_index - n_index + 1;
                n_index = 0;
                
            }
            
            if (n_index == needle.length()) return h_index-n_index;
            
        }
        
        return -1;
        
    }
};
