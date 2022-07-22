class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        // parameters
        int wlen = words[0].length();
        int wnum = words.size();
        int slen = s.length();
        string temp;
        unordered_map<string, int> check, cur;
        vector<int> ans;
        
        // used for checking if all the words appear
        for (auto w : words) check[w]++;
        
        // start compute
        for (int i=0; i<=slen-wnum*wlen; i++) {
            
            // start checking
            for (int j=i; j<i+wnum*wlen; j+=wlen) {
                
                temp = s.substr(j, wlen);
                
                // check if the substring is in the checking list
                if (check.count(temp)!=0) cur[temp]++;
                else break;
                
                // check if the number of the substring is smaller or equal to the checking list
                if (cur[temp] > check[temp]) break;
                
            }
            
            // check if the avode for loop ends with no breaking
            if (cur == check) ans.push_back(i);
            cur.clear();
            
        }
        
        return ans;
        
    }
};
