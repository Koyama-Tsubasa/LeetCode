class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int s_length = s.length();
      
        // to store answer, strting point of unrepeated region, and the characters' last index
        int LSWRC_ans = 0;
        int unrepeated = 0;
        map<char, int> index;
        
        // start compute
        for (int i=0; i<s_length; i++) {
            
            // check if the character appeared before
            if (index.find(s[i]) == index.end()) index[s[i]] = i;
            else {
                
                // calculate the longest substring without repeating characters
                LSWRC_ans = max(LSWRC_ans, i-unrepeated);
              
                // update the starting point of unrepeated region
                if (unrepeated < index[s[i]]+1) unrepeated = index[s[i]]+1;
              
                // update the characters' last index
                index[s[i]] = i;
            
            }
            
        }
        LSWRC_ans = max(LSWRC_ans, s_length-unrepeated);
        
        return LSWRC_ans;
        
    }
};
